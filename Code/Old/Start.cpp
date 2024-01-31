#include "Start.h"

StartScene::StartScene(const sf::Vector2f& windowSize) : startButton(windowSize, "Start"), finished(false) {

    // Load font
    font.loadFromFile("Assets/Font.ttf");

    // Set up the Olympic Games sprite
    sf::Texture texture;
    texture.loadFromFile("Assets/Anneaux.png");
    olympicSprite.setTexture(texture);
    olympicSprite.setScale(0.5f, 0.5f);
    olympicSprite.setOrigin(olympicSprite.getLocalBounds().width / 2.0f, olympicSprite.getLocalBounds().height / 2.0f);
    olympicSprite.setPosition(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f - 100));

    // Set up the Olympic Games text
    olympicText.setFont(font);
    olympicText.setString("Welcome to our Olympic Flame Timeline!\nWe will visualize the history of the Olympic Flame.\n\nClick the button below to start!");
    olympicText.setCharacterSize(24);
    olympicText.setFillColor(sf::Color::Black);

    // center text
    sf::FloatRect textRect = olympicText.getLocalBounds();
    olympicText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    olympicText.setPosition(sf::Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f - 100));

}

void StartScene::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (startButton.isClicked(event)) {
                finished = true;
            }
        }
    }
}

void StartScene::update() {
    // Update logic (if any) for the start scene
}

void StartScene::render(sf::RenderWindow& window) {
    window.clear(sf::Color::White);

    // Render the Olympic sprite and text
    window.draw(olympicSprite);
    window.draw(olympicText);

    // Render the button
    startButton.render(window);

    window.display();
}

bool StartScene::isFinished() const {
    return finished;
}
