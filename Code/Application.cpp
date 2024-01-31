#include "Application.h"
// On va initialiser la fenetre avec une taille de 800x600 et donc evidément avec le le titre "Olympic Games Generator"
// Nous allons aussi initialiser startWindow et gameWindow avec les paramètres de window
// On se place enfin au debut du "jeu" avec currentState qui est un enum qui choisis entre Start et Game
Application::Application() : window(sf::VideoMode(800, 600), "Olympic Games Generator"),
                             startWindow(window),
                             gameWindow(window),
                             currentState(State::Start) {}
// On va donc utiliser cette méthode pour lancer le jeu
void Application::run() {

    while (window.isOpen()) {
        switch (currentState) {
            case State::Start:
                if (gameWindow.run()) { // Si le bouton est cliqué dans GameWindow, on change de fenêtre
                    currentState = State::Game;
                }
                break;
                //Si on est dans le cas Game, on lance startWindow
            case State::Game:
                startWindow.run();
                break;
        }
    }
}
