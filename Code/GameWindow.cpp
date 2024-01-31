#include "GameWindow.h"
// Initialisation de la classe GameWindow avec la fenêtre, le texte, le bouton
GameWindow::GameWindow(sf::RenderWindow& window) : window(window), 
                           text1("Welcome to the Olympic Games Generator!", font, 24, 150, 300),
                           text2("Here, you can learn about a random country.", font, 24, 140, 350),
                           button("Start", font, 320, 440, 120, 50) {
    window.setFramerateLimit(60);// on met les frames à 60 pour que soit fluide
    window.setVerticalSyncEnabled(false);
    // On charge la police et on vérifie si elle est bien chargée
    if (!font.loadFromFile("Assets/Font.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
}
// La méthode permettant de lancer la fenêtre
bool GameWindow::run() {
    while (window.isOpen()) {
        sf::Event event; // On crée un évènement
        while (window.pollEvent(event)) {
            // Si l'évenement qu'on a crée est celui de la fermeture de la fenêtre, alors on ferme la fenêtre
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            }
            // Si l'évenement qu'on a crée est celui d'appuyer sur le bouton gauche de la souris
            if (event.type == sf::Event::MouseButtonPressed) {
                // Alors on vérifie si la souris est sur le bouton
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (button.isMouseOver(window)) {
                        return true;
                    }
                }
            }
        }
        // Petit bout de code permettant de mettre la couleur de la fenêtre en blanc
        // Ainsi que de dessiner le logo, le texte et le bouton et de les afficher
        window.clear(sf::Color::White);
        logo.draw(window);
        text1.draw(window);
        text2.draw(window);
        button.draw(window);
        window.display();
    }

    return false;
}
