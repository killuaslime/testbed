#include "MenuRender.h"
#include <SFML/Graphics.hpp>

MenuRender::MenuRender() {}
void MenuRender::initialize(const sf::Font& font) {
    start.emplace("Start", sf::Vector2f{ 1024.f, 200.f },
        sf::Vector2f{ 200.f, 60.f }, font);
    pause.emplace("Pause", sf::Vector2f{ 1024.f, 200.f },
        sf::Vector2f{ 200.f, 60.f }, font);
    settings.emplace("Settings", sf::Vector2f{ 1024.f, 265.f },
        sf::Vector2f{ 200.f, 60.f }, font);
    quit.emplace("Quit", sf::Vector2f{ 1024.f, 330.f },
        sf::Vector2f{ 200.f, 60.f }, font);
    back.emplace("Back", sf::Vector2f{ 1024.f, 265.f },
        sf::Vector2f{ 200.f, 60.f }, font);
    resume.emplace("Resume", sf::Vector2f{ 1024.f, 200.f },
        sf::Vector2f{ 200.f, 60.f }, font);
    menuTitle.emplace(font);
    menuTitle->setCharacterSize(32);
    menuTitle->setFillColor(sf::Color::White);
    menuTitle->setPosition(sf::Vector2f{ 1024.f, 150.f });
    updateTitle();
    
}
void MenuRender::updateTitle()
{
    switch (CurrentState)
    {
    case MenuState::MainMenu:
        menuTitle->setString("Main Menu");
        break;

    case MenuState::Settings:
        menuTitle->setString("Settings");
        break;

    case MenuState::Game:
        menuTitle->setString("Game");
        break;

    case MenuState::PauseMenu:
        menuTitle->setString("Pause");
        break;

    default:
        break;
    }
}
void MenuRender::handleEvent(const sf::Event & event, sf::RenderWindow & window, std::atomic<bool>& gameRunning) {
    sf::Vector2i mousePixel = sf::Mouse::getPosition(window);
    sf::Vector2f mousePosition = window.mapPixelToCoords(mousePixel);
    if (event.is<sf::Event::Closed>()) {
        window.close();
        gameRunning = false;
    }

    if (const auto* mousePressed = event.getIf<sf::Event::MouseButtonPressed>())
    {
        if (mousePressed->button == sf::Mouse::Button::Left)
        {
            switch (CurrentState)
            {
            case MenuState::MainMenu:
                if (start->isMouseOver(mousePosition))
                {                 
                    CurrentState = MenuState::Game;
                    updateTitle();
                }

                else if (quit->isMouseOver(mousePosition))
                {
                    window.close();
                    gameRunning = false;
                }

                else if (settings->isMouseOver(mousePosition))
                {                    
                    CurrentState = MenuState::Settings;
                    updateTitle();
                }

                break;

            case MenuState::Settings:
                if (back->isMouseOver(mousePosition))
                {
                    CurrentState = MenuState::MainMenu;
                    updateTitle();
                }

                break;

            case MenuState::Game:
                if (pause->isMouseOver(mousePosition))
                {
                    CurrentState = MenuState::PauseMenu;
                    updateTitle();
                }
                if (back->isMouseOver(mousePosition))
                {
                    CurrentState = MenuState::MainMenu;
                    updateTitle();
                }
                break;
            case MenuState::PauseMenu:
                if (resume->isMouseOver(mousePosition))
                {
                    CurrentState = MenuState::Game;
                    updateTitle();
                }
                if (back->isMouseOver(mousePosition))
                {
                    CurrentState = MenuState::MainMenu;
                    updateTitle();
                }
                break;
            default:
                break;
            }
        }
    }
}

void MenuRender::update(sf::Vector2f mousePosition) {
    switch (CurrentState)
    {
    case MenuState::MainMenu:

        start->update(mousePosition);
        quit->update(mousePosition);
        settings->update(mousePosition);
        break;

    case MenuState::Settings:

        back->update(mousePosition);

        break;

    case MenuState::Game:
        pause->update(mousePosition);
        back->update(mousePosition);

        break;
    case MenuState::PauseMenu:
        resume->update(mousePosition);
        back->update(mousePosition);
        break;
    default:
        break;
    }
}

void MenuRender::draw(sf::RenderWindow& window) {
    switch (CurrentState)
    {
    case MenuState::MainMenu:
        window.draw(*menuTitle);
        start->draw(window);
        quit->draw(window);
        settings->draw(window);
        break;

    case MenuState::Settings:
        window.draw(*menuTitle);
        back->draw(window);

        break;

    case MenuState::Game:
        window.draw(*menuTitle);
        pause->draw(window);
        back->draw(window);

        break;
    case MenuState::PauseMenu:
        window.draw(*menuTitle);
        resume->draw(window);
        back->draw(window);
    default:
        break;
    }
}