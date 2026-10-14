#pragma once
#include <string>
#include <mutex>
extern std::mutex playerMutex;
struct Vector3
{
    float x;
    float y;
    float z;
};

struct Player
{
    std::string name;
    std::string team;

    int health;

    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;

    int damage;
    bool isAlive;
};


void updatePosition(Player& player, const float tickInterval);
void takeDamage(Player& player, int damage);
bool isPlayerAlive(const Player& player);
