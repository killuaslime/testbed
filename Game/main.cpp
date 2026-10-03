
#include "Player.h"
#include "Game.h"
#include "Menu.h"
#include <thread>

using namespace std;




int main(){
    Player players[5];
    players[0] = { "Bob", "CT", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 10,true };
    players[1] = { "Kevin", "T", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 10,true };
    players[2] = { "Mike", "CT", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 15,true };
    players[3] = { "John", "T", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 20,true };
    players[4] = { "Alex", "CT", 100, {0, 0, 0},{0, 0, 0},{0, 0, 0}, 10,true };
    bool gameRunning = true;

    std::thread gameThread(gameLoop, players, std::ref(gameRunning));
        
    std::thread menuThread(mainMenu, players, std::ref(gameRunning));
    gameThread.join();
    menuThread.join();
}
