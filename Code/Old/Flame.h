#ifndef FLAME_H
#define FLAME_H

#include <SFML/Graphics.hpp>

class Flame {
public:
    Flame();

    void update();
    void render(sf::RenderWindow& window);

private:
    sf::Texture flameTexture;
    sf::Sprite flameSprite;
};

#endif // FLAME_H
