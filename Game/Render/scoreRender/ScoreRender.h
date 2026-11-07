#pragma once

#include <SFML/Graphics.hpp>
#include "Game.h"

class ScoreRender {
private:
    sf::Font& font;
    sf::Text score;


public:
    explicit ScoreRender(sf::Font& font);

    void update(const MatchScore& matchScore);
    void drawScore(sf::RenderWindow& window) const;
};




