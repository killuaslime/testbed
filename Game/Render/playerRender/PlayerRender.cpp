#include "PlayerRender.h"
#include "Team.h"

#include <mutex>

extern std::mutex playerMutex;

PlayerRender::PlayerRender(sf::Font& font)
    : font(font)
{
}

void PlayerRender::update(const Player players[], int playerCount) {
    std::lock_guard<std::mutex> lock(playerMutex);

    visuals.clear();

    for (int i = 0; i < playerCount; i++) {
        if (!players[i].isPlayerAlive())
            continue;

        PlayerVisual visual(font);

        Vector3 position = players[i].getPosition();

        visual.shape.setPosition({ position.x, position.y });
        visual.shape.setFillColor(players[i].getColor());

        visual.name.setString(players[i].getName());

        sf::FloatRect textBounds = visual.name.getLocalBounds();

        visual.name.setOrigin({
            textBounds.position.x + textBounds.size.x / 2.f,
            textBounds.position.y
            });

        visual.name.setPosition({
            position.x + visual.shape.getRadius(),
            position.y + visual.shape.getRadius() * 2.f + 2.f
            });

        visuals.push_back(visual);
    }
}

void PlayerRender::drawPlayers(sf::RenderWindow& window) const {
    for (const auto& visual : visuals) {
        window.draw(visual.shape);
        window.draw(visual.name);
    }
}