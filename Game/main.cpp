
#include "Player.h"
#include "Game.h"
#include "SpawnManager.h"
#include "Render.h"
#include <thread>
#include <iostream>
#include <atomic>

using namespace std;

SpawnManager spawnManager;
MatchScore score;

int main(){
    std::atomic<bool> gameRunning = true;

    std::array<Player, 10> players = {
    Player("asaka", Team::CT),
    Player("Faqit", Team::CT),
    Player("Senpen Banka", Team::CT),
    Player("Munkao", Team::CT),
    Player("Balja", Team::CT),

    Player("Mavix", Team::T),
    Player("awfax", Team::T),
    Player("emoslut666", Team::T),
    Player("VIPERINSIDE", Team::T),
    Player("zxcursed", Team::T), 
    };

    for (int i = 0; i < 10; i++) {
        spawnManager.spawnPlayer(players[i], i % 5);
    }  

    std::thread gameThread(
        gameLoop,
        players.data(),
        std::ref(gameRunning),
        std::ref(score)
    );

    std::thread renderThread([&]() {
        Renderer renderer(1920, 1080);
        renderer.render(players.data(), 10, gameRunning, score);
        });

    gameThread.join();
    renderThread.join();

    return 0;
}

