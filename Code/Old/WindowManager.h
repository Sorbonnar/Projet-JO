#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class WindowManager {
public:
    WindowManager();
    bool isOpen() const;
    void close();
    void clear();
    void display();
    sf::RenderWindow& getWindow();
    bool pollEvent(sf::Event& event);

    const sf::Font& loadFont(const std::string& path);
    const sf::Font& getDefaultFont() const;
    const sf::Texture& loadTexture(const std::string& path);

private:
    sf::RenderWindow window;
    std::map<std::string, sf::Font> fonts;
    sf::Font defaultFont;
    std::map<std::string, sf::Texture> textures;
};

#endif // WINDOWMANAGER_H
