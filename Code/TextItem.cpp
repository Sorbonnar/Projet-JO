#include "TextItem.h"
TextItem::TextItem() {
    // vide
}
// Connstruteur permettant d'initialiser la classe TextItem avec le texte, la police, la taille et la position
TextItem::TextItem(const std::string& text, const sf::Font& font, unsigned int size, float x, float y) {
    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(size);
    this->text.setPosition(x - this->text.getLocalBounds().width / 2, y - this->text.getLocalBounds().height / 2);
    this->text.setFillColor(sf::Color::Black);
}
// Methode permettant de dessiner le texte sur la fenêtre
void TextItem::draw(sf::RenderWindow& window) {
    window.draw(text);
}
// Méthode permettant de changer le texte
void TextItem::setText(const std::string& newText) {
    text.setString(newText);
}

