#pragma once
#include "Player.h"
#include<mutex>
using namespace std;
extern mutex playerMutex;
void showPlayer(Player& player);
void mainMenu(Player players[], bool& gameRunning);
void playersMenu(Player players[]);
void movementMenu(Player players[]);
void damageMenu(Player players[]);