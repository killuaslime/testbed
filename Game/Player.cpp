#include "Player.h"
#include <mutex>
#include <atomic>
#include <algorithm>
using namespace std;
mutex playerMutex;
//Player::Player(/* параметры */)
//    : /* поле */(/* начальное значение */),
//    /* следующее поле */(/* начальное значение */)
//{
//}


Player::Player(std::string name, Team team)
    : name(name),
    team(team)
{

}
void Player::setColor(sf::Color color) {
    this->color = color;
}

sf::Color Player::getColor() const {
    return color;
}

void Player::setPosition(Vector3 position) {
    this->position = position;
}
void Player::setVelocity(Vector3 velocity) {
    this->velocity = velocity;
}
void Player::setAcceleration(Vector3 acceleration) {
    this->acceleration = acceleration;
}

Vector3 Player::getPosition() const {
    return position;
}
Vector3 Player::getVelocity() const {
    return velocity;
}
Vector3 Player::getAcceleration() const {
    return acceleration;
}

std::string Player::getName() const {
    return name;
}
Team Player::getTeam() const {
    return team;
}
bool Player::isPlayerAlive() const {
    return isAlive;
}

void Player::setWeapons(std::vector<Weapon> weapons) {
    this->weapons = weapons;
}
