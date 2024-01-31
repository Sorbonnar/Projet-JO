#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
#include "WindowManager.h"
#include "Scene.h"

class Application {
public:
    Application();
    void run();

private:
    void processEvents();
    void update();
    void render();

    std::unique_ptr<WindowManager> windowManager;
    std::unique_ptr<Scene> currentScene;
};

#endif // APPLICATION_H
