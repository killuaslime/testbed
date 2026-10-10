
#include "Player.h"
#include "Game.h"
#include "Menu.h"
#include <thread>
#include "Render.h"
#include <iostream>
#include <atomic>
using namespace std;




int main(){
    Player players[5];
    players[0] = { "Bob", "CT", 100, {500, 54, 0},{20, 20, 0},{0, 0, 0}, 10,true };
    players[1] = { "Kevin", "T", 100, {1235, 422, 0},{20, 30, 0},{0, 0, 0}, 10,true };
    players[2] = { "Mike", "CT", 100, {543, 324, 0},{10, 15, 0},{0, 0, 0}, 15,true };
    players[3] = { "John", "T", 100, {345, 123, 0},{40, 5, 0},{0, 0, 0}, 20,true };
    players[4] = { "Alex", "CT", 100, {50, 756, 0},{50, 8, 0},{0, 0, 0}, 10,true };
    std::atomic<bool> gameRunning = true;

    std::thread gameThread(gameLoop, players, std::ref(gameRunning));
    std::thread menuThread(mainMenu, players, std::ref(gameRunning));

    std::thread renderThread([&](){Renderer renderer(1920, 1080);renderer.render(players,5,gameRunning);});

    gameThread.join();
    menuThread.join();
    renderThread.join();


    return 0;
}

