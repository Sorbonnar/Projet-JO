#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>

class Button {
public:
    Button(const sf::Vector2f& position, const std::string& text);

    void render(sf::RenderWindow& window);
    bool isClicked(const sf::Event& event) const;
    bool contains(const sf::Vector2f& point) const;

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font buttonFont;
};

#endif // BUTTON_H
