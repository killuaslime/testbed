#pragma once

#include "SpawnPoint.h"
#include <vector>
#include <cstddef>
#include <array>
#include <SFML/Graphics.hpp>


class SpawnManager
{
private:
    std::vector<SpawnPoint> ctSpawns;
    std::vector<SpawnPoint> tSpawns;
    std::array<sf::Color, 5> colors;


public:
    SpawnManager();

    void spawnPlayer(Player& player, std::size_t spawnIndex);
    void spawnColor(Player& player, std::size_t colorIndex);
};