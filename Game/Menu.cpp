#include "Menu.h"
#include <iostream>
#include <conio.h>
#include "Game.h"
#include"Player.h"

using namespace std;


void mainMenu(Player players[], bool& gameRunning) {
    while (gameRunning == true) {
        cout << " " << endl;
        cout << "====== Counter-Strike 2 ======\n" << endl;

        cout << "         v1.0.1           " << endl;
        cout << "    slow steps to WinAPI       " << endl;
        cout << " " << endl;
        cout << "1. Players menu" << endl;
        cout << "2. Damage menu" << endl;
        cout << "3. movement menu" << endl;
        cout << "4. Show statistic" << endl;
        cout << "5. Exit" << endl;
        int key = _getch();
    

        switch (key) {
        case '1': {
            playersMenu(players);
            break;
        }
        case '2': {
            damageMenu(players);
            break;
        }
        case '3': {
            movementMenu(players);
            break;
        }
        case '4': {
            showTickrate();
            break;
        }

        case '5': {
            gameRunning = false;
            break;
        }
        }
    }
}
void showPlayer(Player& player) {
    lock_guard<mutex> lock(playerMutex);
    cout << " " << endl;
    cout << "Name: " << player.name << endl;
    cout << "Team: " << player.team << endl;
    cout << "Health: " << player.health << endl;
    cout << "Position: "
        << player.position.x << ", "
        << player.position.y << ", "
        << player.position.z << endl;
    if (!player.isAlive)
        cout << "He is dead" << endl;
    else cout << "He is alive" << endl;
    cout << "=====================" << endl;
}
void playersMenu(Player players[]) {
    while (true) {
        cout << " " << endl;
        cout << "1. Show all players" << endl;
        cout << "2. Show selected players" << endl;
        cout << " " << endl;
        cout << "press ESC to return" << endl;
        int key = _getch();
        switch (key) {
        case '1': {
            for (int i = 0; i < 5;i++) {
                showPlayer(players[i]);
            }
            break;
        }
        case '2': {
            int i;
            cout << "Choose players: ";
            cin >> i;
            if (i < 1 || i > 5)
            {
                cout << "Invalid player!" << endl;
                break;
            }
            else {
                showPlayer(players[i - 1]);
            }
            break;
        }
        case 27: {
            return;
        }

        }
    }
}
void damageMenu(Player players[]) {
    while (true) {
        cout << " " << endl;
        cout << "1. Damage player" << endl;
        cout << "2. Show player health" << endl;
        cout << "3. Kill player" << endl;
        cout << " " << endl;
        cout << "press ESC to return" << endl;
        int key = _getch();
        switch (key) {
        case '1': {
            int i;
            cout << " " << endl;
            cout << "Choose players: ";
            cin >> i;

            if (i < 1 || i > 5)
            {
                cout << "Invalid player!" << endl;
                break;
            }
            else {
                cout << "Take damage: ";
                int damage;
                cin >> damage;
                takeDamage(players[i - 1], damage);
            }
            break;
        }
        case '2': {
            cout << " " << endl;
            int i;
            cout << "Choose players: ";
            cin >> i;
            if (i < 1 || i > 5)
            {
                cout << "Invalid player!" << endl;
                break;
            }
            else {
                lock_guard<mutex> lock(playerMutex);
                cout << "Name: " << players[i - 1].name << endl;
                cout << "Health: " << players[i - 1].health << endl;
            }
            break;
        }
        case '3': {
            cout << " " << endl;
            int i;
            cout << "Choose players: ";
            cin >> i;
            if (i < 1 || i > 5)
            {
                cout << "Invalid player!" << endl;
                break;
            }
            else {
                takeDamage(players[i - 1], 1000);
                cout << " " << endl;
                lock_guard<mutex> lock(playerMutex);
                cout << "Health: " << players[i - 1].health << endl;
            }
            break;
        }
        case 27:
            return;
        }

    }

}



void movementMenu(Player players[]) {
    int selectedPlayer = -1;
    while (true) {
        cout << " " << endl;
        cout << "===== Movement Menu =====" << endl;
        cout << " " << endl;
        

        if (selectedPlayer == -1) {
            cout << "Selected player: None" << endl;
        }
        else {
            cout << "Selected player: "
                << players[selectedPlayer - 1].name << endl;
        }
        cout << " " << endl;
        cout << "1. Select player" << endl;
        cout << "2. Show position" << endl;
        cout << "3. Set velocity" << endl;
        cout << "4. Set acceleration" << endl;
        cout << " " << endl;
        cout << "Press ESC to return" << endl;
        int key = _getch();
        switch (key) {
            case '1': 
                cout << "Select player: ";
                int newPlayer;
                cin >> newPlayer;
                if (newPlayer < 1 || newPlayer > 5)
                {
                    cout << " " << endl;
                    cout << "Invalid player!" << endl;
                    break;
                }
                selectedPlayer = newPlayer;
                break;

            case '2': {
                if (selectedPlayer == -1) {
                    cout << " " << endl;
                    cout << "Please select player!" << endl;
                    break;
                }
                else {
                    lock_guard<mutex> lock(playerMutex);
                    cout << " " << endl;
                    cout << "Name: " << players[selectedPlayer - 1].name << endl;
                    cout << "Position: "
                        << players[selectedPlayer - 1].position.x << ", "
                        << players[selectedPlayer - 1].position.y << ", "
                        << players[selectedPlayer - 1].position.z << endl;
                    cout << "Velocity: "
                        << players[selectedPlayer - 1].velocity.x << ", "
                        << players[selectedPlayer - 1].velocity.y << ", "
                        << players[selectedPlayer - 1].velocity.z << endl;
                    cout << "Acceleration: "
                        << players[selectedPlayer - 1].acceleration.x << ", "
                        << players[selectedPlayer - 1].acceleration.y << ", "
                        << players[selectedPlayer - 1].acceleration.z << endl;
                    break;
                }
                
            }
            case '3': {
                if (selectedPlayer == -1) {
                    cout << " " << endl;
                    cout << "Please select player!" << endl;
                    break;
                }
                else {
                    float x, y, z;
                    cout << " " << endl;
                    cout << "Set new velocity X: ";
                    cin >> x;
                    cout << "Set new velocity Y: ";
                    cin >> y;
                    cout << "Set new velocity Z: ";
                    cin >> z;
                    cout << " " << endl;
                    cout << "NEW velocity: "
                        << x << ", "
                        << y << ", "
                        << z << endl;
                    lock_guard<mutex> lock(playerMutex);
                    players[selectedPlayer - 1].velocity.x = x;
                    players[selectedPlayer - 1].velocity.x = y;
                    players[selectedPlayer - 1].velocity.x = z;
                    break;
                }

            }
            case '4': {
                if (selectedPlayer == -1) {
                    cout << " " << endl;
                    cout << "Please select player!" << endl;
                    break;
                }
                else {
                    float x, y, z;
                    cout << " " << endl;
                    cout << "Set new acceleration X: ";
                    cin >> x;
                    cout << "Set new acceleration Y: ";
                    cin >> y;
                    cout << "Set new acceleration Z: ";
                    cin >> z;
                    cout << " " << endl;
                    cout << "NEW acceleration: "
                        << x << ", "
                        << y << ", "
                        << z << endl;
                    lock_guard<mutex> lock(playerMutex);
                    players[selectedPlayer - 1].acceleration.x = x;
                    players[selectedPlayer - 1].acceleration.x = y;
                    players[selectedPlayer - 1].acceleration.x = z;
                    break;
                }

            }
            case 27: {
                return;
            }
        }
    }
}