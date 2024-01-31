#ifndef TIMELINE_H
#define TIMELINE_H

#include "Scene.h"
#include <SFML/Graphics.hpp>

class TimelineScene : public Scene {
public:
    TimelineScene();
    void handleEvent(const sf::Event& event) override;
    void update() override;
    void render(sf::RenderWindow& window) override;
    bool isFinished() const override;

private:
    // Attributes specific to the timeline scene, like sprites, texts, etc.
};

#endif // TIMELINE_H
