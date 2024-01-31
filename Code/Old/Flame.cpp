#include "Flame.h"

Flame::Flame() {
    // Load the flame texture
    flameTexture.loadFromFile("../Assets/Flame.png");

    // Set up the sprite
    flameSprite.setTexture(flameTexture);
}

void Flame::update() {
    // Update flame animation or state if needed
}

void Flame::render(sf::RenderWindow& window) {
    window.draw(flameSprite);
}
