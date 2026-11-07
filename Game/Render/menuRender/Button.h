#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button
{
private:
	sf::RectangleShape shape;
	sf::Text text;

public:
	Button(const std::string& label, sf::Vector2f position, sf::Vector2f size, const sf::Font& font);
	void draw(sf::RenderWindow& window);
	void update(sf::Vector2f mousePosition);
};