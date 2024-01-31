#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include "TextItem.h"

class Button {
public:
    Button(const std::string& text, const sf::Font& font, float x, float y, float width, float height);
    void draw(sf::RenderWindow& window);
    bool isMouseOver(sf::RenderWindow& window);

private:
    sf::RectangleShape shape;
    TextItem buttonText;
};

#endif // BUTTON_H
