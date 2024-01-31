#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include "StartWindow.h"
#include "GameWindow.h"

class Application {
public:
    Application();
    void run();

private:
    sf::RenderWindow window;
    StartWindow startWindow;
    GameWindow gameWindow;
    enum class State {
        Start,
        Game
    };
    State currentState;
};

#endif // APPLICATION_H
