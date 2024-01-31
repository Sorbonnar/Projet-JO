#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <SFML/Graphics.hpp>
#include "Logo.h"
#include "TextItem.h"
#include "Button.h"

class GameWindow {
public:
    GameWindow(sf::RenderWindow& window);
    bool run();

private:
    sf::RenderWindow& window;
    sf::Font font;
    Logo logo;
    TextItem text1, text2;
    Button button;
};


#endif // GAMEWINDOW_H
