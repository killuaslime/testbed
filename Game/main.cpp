
#include "Player.h"
#include "Game.h"
#include "Menu.h"
#include "SpawnManager.h"
#include "Render.h"
#include <thread>
#include <iostream>
#include <atomic>

using namespace std;

SpawnManager spawnManager;


int main(){
    Player players[10];

    players[0] = { "autostrafe. asaka", "CT", 100, {0, 0, 0},{0, 10, 0},{0, 0, 0}, 10,true };
    players[1] = { "gospodispasi Faqit", "CT", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 10,true };
    players[2] = { "Senpen Banka", "CT", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 15,true };
    players[3] = { "Munkao", "CT", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 20,true };
    players[4] = { "emo4ka Balzhinima", "CT", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 10,true };
    players[5] = { "Bob", "T", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 10,true };
    players[6] = { "Kevin", "T", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 10,true };
    players[7] = { "Mike", "T", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 15,true };
    players[8] = { "John", "T", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 20,true };
    players[9] = { "Alex", "T", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 10,true };
    for (int i = 0; i < 10; i++) {
        spawnManager.spawnPlayer(players[i], i % 5);
    }
    std::atomic<bool> gameRunning = true;

    std::thread gameThread(gameLoop, players, std::ref(gameRunning));
    //std::thread menuThread(mainMenu, players, std::ref(gameRunning));

    std::thread renderThread([&](){Renderer renderer(1920, 1080);renderer.render(players,10,gameRunning);});

    gameThread.join();
    //menuThread.join();
    renderThread.join();


    return 0;
}

