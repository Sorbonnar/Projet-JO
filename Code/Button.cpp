#include "Button.h"
//Initialisation de la classe Button avec le texte, la police, la position, la taille et la couleur( du bouton à l'interieur ainsi que de son contour)
Button::Button(const std::string& buttonText, const sf::Font& font, float x, float y, float width, float height) : buttonText(buttonText, font, 24, x + width / 4, y + 10) {
    shape.setSize(sf::Vector2f(width, height));//On initialise avec les données en argument pour ce qu'on a besoin
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::White);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(2);
}
// La méthode servant à dessiner le bouton et le texte sur la fenêtre
void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    buttonText.draw(window); 
}
// Méthode servant à savoir si le souris est sur le bouton
bool Button::isMouseOver(sf::RenderWindow& window) {
    // On va simplement recupérer la position de la souris
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    // On va aussi recupérer la position du bouton
    sf::FloatRect buttonRect = shape.getGlobalBounds();
    // On compare les deux positions pour savoir si la souris est bien sur le bouton
    return buttonRect.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
}
