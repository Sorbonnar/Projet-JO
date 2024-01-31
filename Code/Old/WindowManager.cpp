#include "WindowManager.h"

WindowManager::WindowManager() {
    // Create the SFML window
    window.create(sf::VideoMode(800, 600), "Olympic Flame Timeline");

    // Disable vertical sync
    window.setVerticalSyncEnabled(false);

    // Load the default font
    if (!defaultFont.loadFromFile("Assets/Font.ttf")) {
        throw std::runtime_error("Failed to load default font");
    }
}

bool WindowManager::isOpen() const {
    return window.isOpen();
}

void WindowManager::close() {
    window.close();
}

void WindowManager::clear() {
    window.clear();
}

void WindowManager::display() {
    window.display();
}

sf::RenderWindow& WindowManager::getWindow() {
    return window;
}

bool WindowManager::pollEvent(sf::Event& event) {
    return window.pollEvent(event);
}

const sf::Font& WindowManager::loadFont(const std::string& path) {
    auto it = fonts.find(path);
    if (it == fonts.end()) {
        sf::Font& font = fonts[path];
        if (!font.loadFromFile(path)) {
            throw std::runtime_error("Failed to load font: " + path);
        }
        return font;
    }
    return it->second;
}

const sf::Font& WindowManager::getDefaultFont() const {
    return defaultFont;
}

const sf::Texture& WindowManager::loadTexture(const std::string& path) {
    auto it = textures.find(path);
    if (it == textures.end()) {
        sf::Texture& texture = textures[path];
        if (!texture.loadFromFile(path)) {
            throw std::runtime_error("Failed to load texture: " + path);
        }
        return texture;
    }
    return it->second;
}
