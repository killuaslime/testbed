#pragma once

#include "RenderIncludes.h"

#include <mutex>
#include <atomic>

extern std::mutex playerMutex;
class Renderer
{
public:
    Renderer(int width, int height);

    void render(const Player players[], int playerCount, std::atomic<bool>& gameRunning, MatchScore& score);

private:
private:
    sf::RenderWindow window;
    sf::Font font;
    MapRenderer mapRenderer;
    HudRender hudRenderer;
    ScoreRender scoreRenderer;
    PlayerRender playerRenderer;
};