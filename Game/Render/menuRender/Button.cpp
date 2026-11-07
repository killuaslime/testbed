#include "Button.h"
Button::Button(
    const std::string& label,
    sf::Vector2f position,
    sf::Vector2f size,
    const sf::Font& font
)
    : shape(size), text(font)
{
    shape.setPosition(position);
    shape.setFillColor(sf::Color(187, 137, 210));
    text.setString(label);
    text.setFillColor(sf::Color::Black);
    text.setOrigin(text.getLocalBounds().getCenter());
    text.setPosition({position.x + size.x / 2.0f, position.y + size.y / 2.0f});
}
void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(text);
}

void Button::update(sf::Vector2f mousePosition)
{
    if (shape.getGlobalBounds().contains(mousePosition))
    {
        // Курсор находится над кнопкой
        shape.setFillColor(sf::Color{ 150, 100, 180 });
    }
    else
    {
        // Курсор вне кнопки
        shape.setFillColor(sf::Color{ 187, 137, 210 });
    }
}