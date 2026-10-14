#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Game.h"
#include <mutex>
#include <atomic>
extern std::mutex playerMutex;
class Renderer
{
public:
    Renderer(int width, int height);

    void render(const Player players[], int playerCount, std::atomic<bool>& gameRunning, MatchScore& score);

private:
    sf::RenderWindow window;
};