#ifndef LOGO_H
#define LOGO_H

#include <SFML/Graphics.hpp>

class Logo {
public:
    Logo();
    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture;
    sf::Sprite sprite;
};

#endif // LOGO_H
