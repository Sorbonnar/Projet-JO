#ifndef SCENE_H
#define SCENE_H

#include <SFML/Graphics.hpp>

class Scene {
public:
    virtual ~Scene() = default;
    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual bool isFinished() const = 0;
};

#endif // SCENE_H
