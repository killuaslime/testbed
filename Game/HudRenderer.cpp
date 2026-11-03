#include "HudRenderer.h"

HudRender::HudRender(sf::Font& font)
    : font(font), fps(font), tps(font)
{
}
void HudRender::update(float currentFPS, const TickStats& stats) {
    fps.setString("FPS: " + std::to_string(static_cast<int>(currentFPS)) + " rates");
    fps.setCharacterSize(20);
    fps.setFillColor(sf::Color::Green);
    fps.setPosition({ 0.f, 0.f });

    tps.setString("Tickrate: " + std::to_string(static_cast<int>(stats.actualTickrate)));
    tps.setCharacterSize(20);
    tps.setFillColor(sf::Color::Green);
    tps.setPosition({ 0.f, 21.f });
}

void HudRender::drawHud(sf::RenderWindow& window) const {
    window.draw(fps);
    window.draw(tps);
}