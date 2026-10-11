#pragma once

#include "SpawnPoint.h"
#include <vector>
#include <cstddef>

class SpawnManager
{
private:
    std::vector<SpawnPoint> ctSpawns;
    std::vector<SpawnPoint> tSpawns;

public:
    SpawnManager();

    void spawnPlayer(Player& player, std::size_t spawnIndex);
};