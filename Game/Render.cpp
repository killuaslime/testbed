#include "Render.h"


#include "Team.h"
#include <iostream>

#include <deque>


Renderer::Renderer(int width, int height)
    : window(sf::VideoMode(sf::Vector2u{
        static_cast<unsigned int>(width),
        static_cast<unsigned int>(height)
        }, 32), "CS2.exe"),
    hudRenderer(font),
    scoreRenderer(font),
    playerRenderer(font)
{
    window.setFramerateLimit(144);
}

void Renderer::render(const Player players[], int playerCount, std::atomic<bool>& gameRunning,MatchScore& score){

    if (!font.openFromFile("assets/fonts/Jonova-Regular.ttf")) {
        std::cout << "Не удалось загрузить шрифт\n";
        return;
    }
    if (!mapRenderer.loadMap()) {
        return;
    }

    Button start("Start", { 1024.0f, 200.0f }, { 200.0f,60.0f }, font);
    Button quit("Quit", { 1024.0f, 265.0f }, { 200.0f,60.0f }, font);

    sf::Color color;

    sf::Clock clock;
    std::deque<float> fpsHistory;
    float currentFPS = 0.0f;
    while (gameRunning) {
        // =========================
        // Обработка кнопок при наведении
        // =========================
        sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel);
        start.update(mousePosition);
        quit.update(mousePosition);


        sf::Time elapsed = clock.restart();
        currentFPS = 1.0f / elapsed.asSeconds();

        fpsHistory.push_back(currentFPS);
        if (fpsHistory.size() > 60)
            fpsHistory.pop_front();
        float averageFPS = 0.0f;
        for (float fps : fpsHistory)
            averageFPS += fps;
        averageFPS /= fpsHistory.size();

        TickStats stats = getTickStats();

        hudRenderer.update(averageFPS, stats);

        scoreRenderer.update(score);

        window.clear(sf::Color::Black);

        mapRenderer.drawMap(window);

        start.draw(window);
        quit.draw(window);

        playerRenderer.update(players, playerCount);
        playerRenderer.drawPlayers(window);

        scoreRenderer.drawScore(window);

        hudRenderer.drawHud(window);

        window.display();
    }

}