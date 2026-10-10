#pragma once
#include "Player.h"
#include <atomic>

struct TickStats
{
    int ticksProcessed;
    double elapsedTime;
    double actualTickrate;
};
TickStats getTickStats();
void gameTick(Player players[], int playerCount, const float tickInterval);
void calculateTick(Player players[]);
void gameLoop(Player players[], std::atomic<bool>& gameRunning);
void showTickrate();