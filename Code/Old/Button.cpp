#include "Button.h"

Button::Button(const sf::Vector2f& position, const std::string& text) {
    // Load font
    buttonFont.loadFromFile("Assets/Font.ttf");

    // Set up the button shape
    buttonShape.setSize(sf::Vector2f(100, 50));
    buttonShape.setOrigin(buttonShape.getSize().x * 4.5f, buttonShape.getSize().y * 4.5f);
    buttonShape.setPosition(position);


    // Set up the text
    buttonText.setFont(buttonFont);
    buttonText.setString(text);
    buttonText.setCharacterSize(24);
    // text color
    buttonText.setFillColor(sf::Color::Black);
    buttonText.setOrigin(buttonShape.getSize().x * 4.5f - 22, buttonShape.getSize().y * 4.5f - 10);
    buttonText.setPosition(position);

       
    // border colors
    buttonShape.setOutlineColor(sf::Color::Black);
    buttonShape.setOutlineThickness(2);
    // fill color
    buttonShape.setFillColor(sf::Color::White);
}


void Button::render(sf::RenderWindow& window) {
    window.draw(buttonShape);
    window.draw(buttonText);
}

bool Button::isClicked(const sf::Event& event) const {
    // Check if the button is clicked
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            return contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
        }
    }
    return false;
}

bool Button::contains(const sf::Vector2f& point) const {
    // Check if the point is inside the button
    return buttonShape.getGlobalBounds().contains(point);
}
