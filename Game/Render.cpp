#include "Render.h"


#include "Team.h"
#include <iostream>

#include <deque>
#include <optional>


Renderer::Renderer(int width, int height)
    : window(sf::VideoMode(sf::Vector2u{
        static_cast<unsigned int>(width),
        static_cast<unsigned int>(height)
        }, 32), "CS2.exe"),
    hudRenderer(font),
    scoreRenderer(font),
    playerRenderer(font),
    menuRenderer()
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

    sf::Clock clock;
    std::deque<float> fpsHistory;
    float currentFPS = 0.0f;
    while (gameRunning) {
        menuRenderer.initialize(font);
        sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
        sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel);


        while (const std::optional event = window.pollEvent()){
            menuRenderer.handleEvent(*event, window, gameRunning);
        }



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
        menuRenderer.update(mousePosition);

        window.clear();

        mapRenderer.drawMap(window);
        playerRenderer.update(players, playerCount);
        playerRenderer.drawPlayers(window);
        scoreRenderer.drawScore(window);
        hudRenderer.drawHud(window);
        menuRenderer.draw(window);

        window.display();
    }

}