#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <sstream>
#include "Button.h"
#include "TextItem.h" 

class CountryInfo {
public:
    std::string code;
    std::string name;
    std::string description;
    int gold;
    int silver;
    int bronze;

    CountryInfo(const std::string& line);
    friend std::ostream& operator<<(std::ostream& os, const CountryInfo& ci);
    bool operator==(const CountryInfo& other) const { return code == other.code; }
};


class StartWindow {
public:
    StartWindow(sf::RenderWindow& window);
    void loadCountryData();
    void run();

private:
    sf::RenderWindow& window;
    sf::Font font;
    Button startButton;
    TextItem countryName;
    TextItem countryDescription;
    TextItem goldMedals;
    TextItem silverMedals;
    TextItem bronzeMedals;
    CountryInfo* currentCountry = nullptr;
    sf::Sprite flagSprite;
    sf::Texture flagTexture;

    void displayCountryInfo();
    CountryInfo* getRandomCountry();
};

#endif // STARTWINDOW_H
