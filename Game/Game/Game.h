#pragma once
#include "Player.h"
#include <atomic>
#include <mutex>

extern std::mutex roundsMutex;

struct TickStats
{
    int ticksProcessed;
    double elapsedTime;
    double actualTickrate;
};
struct MatchScore
{
    int ctScore = 0;
    int tScore = 0;
    bool roundEnded = false;
};

enum class RoundResult {
    Ongoing,
    CTwin,
    Twin,
    Draw

};

TickStats getTickStats();

void gameTick(Player players[], int playerCount, const float tickInterval, MatchScore& score);
void calculateTick(Player players[], MatchScore& score);
void gameLoop(Player players[], std::atomic<bool>& gameRunning, MatchScore& score);
void showTickrate();

RoundResult checkRoundResult(const Player players[], int playerCount);
void updateRound(const Player players[],int playerCount, MatchScore& score);