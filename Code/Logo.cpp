#include "Logo.h"
// On initialise la classe Logo avec la texture de l'image
Logo::Logo() {
    if (!texture.loadFromFile("Assets/Anneaux.png")) {
        throw std::runtime_error("Failed to load logo texture");
    }
    // On va positionner le logo dans l'endroit voulu et le dimensionner
    sprite.setTexture(texture);
    sprite.setPosition(800 - sprite.getLocalBounds().width / 3.5, 600 - sprite.getLocalBounds().height / 1.8);
    sprite.setScale(0.16, 0.16);
}
// Méthode pour dessiner le logo sur la fenêtre
void Logo::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
