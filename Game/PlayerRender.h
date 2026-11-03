#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"

class PlayerRender {
private:
    sf::Font& font;

    struct PlayerVisual {
        sf::CircleShape shape;
        sf::Text name;

        explicit PlayerVisual(sf::Font& font)
            : shape(8.f), name(font)
        {
            name.setCharacterSize(15);
            name.setFillColor(sf::Color::White);
        }
    };

    std::vector<PlayerVisual> visuals;

public:
    explicit PlayerRender(sf::Font& font);

    void update(const Player players[], int playerCount);
    void drawPlayers(sf::RenderWindow& window) const;
};