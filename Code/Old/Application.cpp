#include "Application.h"
#include "WindowManager.h"
#include "Scene.h"
#include "Start.h"
#include "Timeline.h"
#include <memory>

Application::Application() {
    // Initialize the WindowManager (creates the SFML window)
    windowManager = std::make_unique<WindowManager>();

    // Load resources, initialize scenes, etc.
    sf::Vector2f windowSize(windowManager->getWindow().getSize().x, 
                            windowManager->getWindow().getSize().y);
    currentScene = std::make_unique<StartScene>(windowSize);
}

void Application::run() {
    while (windowManager->isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Application::processEvents() {
    sf::Event event;
    while (windowManager->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            windowManager->close();
        }

        // Delegate event handling to the current scene
        currentScene->handleEvent(event);
    }
}

void Application::update() {
    // Update the current scene
    currentScene->update();

    // Example: Switch to TimelineScene when StartScene signals it's done
    // Ensure that TimelineScene is properly implemented
    if (currentScene->isFinished()) {
        currentScene = std::make_unique<TimelineScene>();
    }
}

void Application::render() {
    windowManager->clear();

    // Render the current scene
    currentScene->render(windowManager->getWindow());

    windowManager->display();
}
