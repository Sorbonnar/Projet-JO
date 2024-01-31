#ifndef TEXTITEM_H
#define TEXTITEM_H

#include <SFML/Graphics.hpp>

class TextItem {
public:
    TextItem();
    TextItem(const std::string& text, const sf::Font& font, unsigned int size, float x, float y);
    void draw(sf::RenderWindow& window);
    void setText(const std::string& newText);

private:
    sf::Text text;
};


#endif // TEXTITEM_H

