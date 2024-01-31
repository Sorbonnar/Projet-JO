#include <SFML/Graphics.hpp>
/*
int main() {
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Olympic Flame History");

    window.setFramerateLimit(60); // Limite la fenêtre à 60 FPS
    window.setVerticalSyncEnabled(false);

    // Chargement du logo
    sf::Texture logoTexture;
    if (!logoTexture.loadFromFile("Assets/Anneaux.png")) {
        return -1;
    }
    sf::Sprite logo(logoTexture);
    logo.setPosition(800 - logo.getLocalBounds().width / 3.5, 600 - logo.getLocalBounds().height / 1.8); // Ajuster la position
    logo.setScale(0.16, 0.16);

    // Création du texte
    sf::Font font;
    if (!font.loadFromFile("Assets/Font.ttf")) {
        return -1;
    }
    sf::Text text("Welcome to the Olympic Flame Timeline!", font, 24);
    text.setPosition(400 - text.getLocalBounds().width / 2, 300 - text.getLocalBounds().height / 2); // Ajuster la position
    sf::Text text2("Click here to start!", font, 24);
    text2.setPosition(400 - text2.getLocalBounds().width / 2, 350 - text2.getLocalBounds().height / 2); // Ajuster la position

    text.setFillColor(sf::Color::Black);
    text2.setFillColor(sf::Color::Black);

    // Création du bouton avec texte
    sf::RectangleShape button(sf::Vector2f(200, 50));
    button.setPosition(300, 470);
    button.setFillColor(sf::Color::White);
    button.setOutlineColor(sf::Color::Black);
    button.setOutlineThickness(2);

    // Création du texte du bouton
    sf::Text buttonText("Discover", font, 24);
    buttonText.setPosition(400 - buttonText.getLocalBounds().width / 2, 470 - buttonText.getLocalBounds().height / 2 + 20); // Ajuster la position
    buttonText.setFillColor(sf::Color::Black);




    // Boucle de la fenêtre
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(logo);
        window.draw(text);
        window.draw(text2);
        window.draw(button);
        window.draw(buttonText);
        window.display();
    }

    return 0;
}
*/