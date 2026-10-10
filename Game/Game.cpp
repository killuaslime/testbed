#include "Game.h"
#include <atomic>
#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
using namespace std;
std::mutex statsMutex;

const float tickRate = 64.0f;
const float tickInterval = 1.0f / tickRate;

int tick = 0;
double accumulator = 0.0;
int ticksProcessed = 0;
auto previous = chrono::steady_clock::now();
auto statStart = chrono::steady_clock::now();

void gameTick(Player players[], int playerCount, const float tickInterval) {
    for (int i = 0; i < playerCount;i++) {

        updatePosition(players[i], tickInterval);
        // Здесь позже будут:
        // столкновения
        // урон
        // смерть
        // и т.д.
    }
}
void showTickrate()
{
    TickStats stats = getTickStats();

    cout << "====== Tick Statistic ======" << endl;
    cout << "Target tickrate: " << tickRate << endl;
    cout << "Tick Processed: " << stats.ticksProcessed << endl;
    cout << "Elapsed time: " << stats.elapsedTime << endl;
    cout << "Actual Tickrate: " << stats.actualTickrate << endl;
}
TickStats lastTickStats{};
TickStats getTickStats(){
    lock_guard<mutex> lock(statsMutex);
    return lastTickStats;
}
void calculateTick(Player players[]) {
    auto current = chrono::steady_clock::now();
    double frameTime = chrono::duration<double>(current - previous).count();
    previous = current;
    accumulator += frameTime;
    while (accumulator >= tickInterval) {
        gameTick(players, 5, tickInterval);
        tick++;
        ticksProcessed++;
        accumulator -= tickInterval;
    }
    auto statCurrent = chrono::steady_clock::now();

    double statElapsed =
        chrono::duration<double>(statCurrent - statStart).count();

    if (statElapsed >= 1.0)
    {
        lock_guard<mutex> lock(statsMutex);
        lastTickStats.ticksProcessed = ticksProcessed;
        lastTickStats.elapsedTime = statElapsed;
        lastTickStats.actualTickrate =
            ticksProcessed / statElapsed;

        ticksProcessed = 0;
        statStart = statCurrent;
    }
    this_thread::sleep_for(chrono::milliseconds(1));
}

void gameLoop(Player players[], std::atomic<bool>& gameRunning){
    while (gameRunning){
        calculateTick(players);
    }
}

