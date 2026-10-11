#include "Render.h"
#include "Player.h"
#include <iostream>
#include <atomic>
#include <deque>
Renderer::Renderer(int width, int height)
    : window(sf::VideoMode(sf::Vector2u{ static_cast<unsigned int>(width),static_cast<unsigned int>(height) }, 32), "CS2.exe")
{
    window.setFramerateLimit(144); /*lock fps до 144 кадров, если не сделать, то sfml может показывать 1500+ кадров, что не очень выглядит*/
}

void Renderer::render(const Player players[], int playerCount, std::atomic<bool>& gameRunning){

    sf::Font font;
    if (!font.openFromFile("assets/fonts/Jonova-Regular.ttf")) {
        std::cout << "Не удалось загрузить шрифт\n";
        return;
    }
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("assets/maps/de_mirage.png"))
    {
        std::cerr << "Не удалось загрузить карту!\n";
        return;
    }

    sf::Sprite mapSprite(mapTexture);



    sf::Text fpstxt(font);
    sf::Text ticktxt(font);

    sf::Clock clock;
    std::deque<float> fpsHistory;
    float currentFPS = 0.0f;
    while (gameRunning) {

        // =========================
        // Подсчет FPS, считаем среднее за 60 кадров
        // =========================
        sf::Time elapsed = clock.restart();
        currentFPS = 1.0f / elapsed.asSeconds();

        fpsHistory.push_back(currentFPS);
        if (fpsHistory.size() > 60)
            fpsHistory.pop_front();
        float averageFPS = 0.0f;
        for (float fps : fpsHistory)
            averageFPS += fps;
        averageFPS /= fpsHistory.size();

        fpstxt.setString("FPS: "+ std::to_string(static_cast<int>(averageFPS))+ " rates");
        fpstxt.setCharacterSize(20);
        fpstxt.setFillColor(sf::Color::Green);
        fpstxt.setPosition({ 0.f, 0.f });

        // =========================
        // Получение Tickrate из game.cpp
        // =========================
        TickStats stats = getTickStats();
        ticktxt.setString("Tickrate: " + std::to_string(static_cast<int>(stats.actualTickrate)));
        ticktxt.setCharacterSize(20);
        ticktxt.setFillColor(sf::Color::Green);
        ticktxt.setPosition({ 0.f, 21.f });

        window.clear(sf::Color::Black);
        // =========================
        // Отрисовка игроков
        // =========================

        window.draw(mapSprite); /* отрисовка de_mirage.png */

        for (int i = 0; i < playerCount; i++) {
            bool alive;
            float x;
            float y;
            std::string team;
            std::string name;

            {
                std::lock_guard<std::mutex> lock(playerMutex);

                alive = players[i].isAlive;
                x = players[i].position.x;
                y = players[i].position.y;
                name = players[i].name;
                team = players[i].team;
            }

            if (!alive)
                continue;
            sf::Text nametxt(font);
            nametxt.setString(name);
            nametxt.setCharacterSize(15);
            nametxt.setFillColor(sf::Color::White);
            nametxt.setPosition({ x-35.0f, y});
            sf::CircleShape playerShape(8.f);
            if (team == "CT") {
                playerShape.setFillColor(sf::Color::Blue);
            }
            else playerShape.setFillColor(sf::Color::Red);

            playerShape.setPosition({
                x,
                y
                });
            window.draw(playerShape);
            window.draw(nametxt);
        }
        window.draw(fpstxt);
        window.draw(ticktxt);
        window.display();
    }

}