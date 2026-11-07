#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

class HudRender {
private:
    sf::Font& font;
    sf::Text fps;
    sf::Text tps;

public:
    explicit HudRender(sf::Font& font);

    void update(float currentFPS, const TickStats& stats);
    void drawHud(sf::RenderWindow& window) const;
};