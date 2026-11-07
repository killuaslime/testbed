#pragma once
#include "MenuState.h"
#include "Button.h"
#include <optional>
class MenuRender{
private:
    MenuState CurrentState = MenuState::MainMenu;
    std::optional<Button> start;
    std::optional<Button> quit;
    std::optional<Button> pause;
    std::optional<Button> settings;
    std::optional<Button> back;
    std::optional<Button> resume;
    std::optional<sf::Text> menuTitle;
public:
    MenuRender();
    void initialize(const sf::Font& font);
    void updateTitle();
    void handleEvent(const sf::Event& event, sf::RenderWindow& window, std::atomic<bool>& gameRunning);
    void update(sf::Vector2f mousePosition);
    void draw(sf::RenderWindow& window);
};

