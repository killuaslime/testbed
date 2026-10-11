#include "Player.h"
#include <mutex>
#include <atomic>
#include <algorithm>
using namespace std;
mutex playerMutex;

void updatePosition(Player& player, const float tickInterval)
{
    lock_guard<mutex> lock(playerMutex);
    
    player.velocity.x += player.acceleration.x * tickInterval;
    player.velocity.y += player.acceleration.y * tickInterval;
    player.velocity.z += player.acceleration.z * tickInterval;
    player.position.x += player.velocity.x * tickInterval;
    player.position.y += player.velocity.y * tickInterval;
    player.position.z += player.velocity.z * tickInterval;
    player.position.x = std::clamp(player.position.x, 100.0f, 920.0f);
    player.position.y = std::clamp(player.position.y, 100.0f, 850.0f);
    if (player.position.x >= 920.0f) {
        player.position.x = 920.0f;
        player.velocity.x = 0.0f;
        player.acceleration.x = 0.0f;
    }
    if (player.position.y >= 850.0f) {
        player.position.y = 850.0f;
        player.velocity.y = 0.0f;
        player.acceleration.y = 0.0f;
    }
    if (player.position.x <= 100.0f) {
        player.position.x = 100.0f;
        player.velocity.x = 0.0f;
        player.acceleration.x = 0.0f;
    }
    if (player.position.y <= 100.0f) {
        player.position.y = 100.0f;
        player.velocity.y = 0.0f;
        player.acceleration.y = 0.0f;
    }
}


void takeDamage(Player& player, int damage)
{
    lock_guard<mutex> lock(playerMutex);
    if (!player.isAlive)
        return;
    player.health -= damage;

    if (player.health <= 0)
    {
        player.health = 0;
        player.isAlive = false;
        player.position.x = 0;
        player.position.y = 0;

    }
}


bool isPlayerAlive(const Player& player)
{
    return player.isAlive;
}