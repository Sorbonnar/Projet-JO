#ifndef START_H
#define START_H

#include "Scene.h"
#include "Button.h"
#include <SFML/Graphics.hpp>

class StartScene : public Scene {
public:
    StartScene(const sf::Vector2f& windowSize);
    void handleEvent(const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    bool isFinished() const override;

private:
    Button startButton;
    sf::Sprite olympicSprite;
    sf::Text olympicText;
    sf::Font font;
    bool finished;
};

#endif // START_H
