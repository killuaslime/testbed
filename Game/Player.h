#pragma once
#include <string>
#include <mutex>
#include "Weapon.h"
#include "Team.h"
#include <vector>

#include <SFML/Graphics.hpp>

extern std::mutex playerMutex;

struct Vector3
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
};

class Player {
private:
    std::string name;
    Team team;

    sf::Color color = {0,0,0};

    int health = 100;
    bool isAlive = true;

    Vector3 position;
    Vector3 velocity;
    Vector3 acceleration;

    std::vector<Weapon> weapons;
    std::size_t activeWeaponIndex = 0;
public:
    Player(std::string name, Team team);

    void setColor(sf::Color color);
    sf::Color getColor() const;

    void setPosition(Vector3 position);
    void setVelocity(Vector3 velocity);
    void setAcceleration(Vector3 acceleration);
    Vector3 getPosition() const;
    Vector3 getVelocity() const;
    Vector3 getAcceleration() const;
    
    void getDamage(std::size_t activeWeaponIndex);
    void setWeapons(std::vector<Weapon> weapons);
    std::string getName() const;
    Team getTeam() const;

    bool isPlayerAlive() const;
};


//Player::Player(/* параметры */)
//    : /* поле */(/* начальное значение */),
//    /* следующее поле */(/* начальное значение */)
//{
//}