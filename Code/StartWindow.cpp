#include "StartWindow.h"
#include <fstream>
#include <iostream>
#include <random>
#include "TextItem.h"

// Variables globales au lieu de membres de classe car on avait des erreurs de segmentation
std::vector<CountryInfo> countries_list; // Liste pour stocker les informations des pays
std::map<std::string, sf::Texture> flagTextures; // Map pour stocker les textures des drapeaux

// Surcharge de l'opérateur << pour afficher les informations d'un pays
std::ostream& operator<<(std::ostream& os, const CountryInfo& ci) {
    os << "Country: " << ci.name << " (Code: " << ci.code << ")"
       << "\nNumber of Participations: " << ci.description
       << "\nGold Medals: " << ci.gold
       << "\nSilver Medals: " << ci.silver
       << "\nBronze Medals: " << ci.bronze;
    return os;
}

// Constructeur pour initialiser un objet CountryInfo à partir d'une ligne de texte
CountryInfo::CountryInfo(const std::string& line) {
    // Extraction des informations du pays
    std::istringstream iss(line);
    std::getline(iss, code, ';');
    std::getline(iss, name, ';');
    std::getline(iss, description, ';');

    // Extraction et conversion des médailles d'or, d'argent et de bronze
    std::string goldStr, silverStr, bronzeStr;
    std::getline(iss, goldStr, ';');
    std::getline(iss, silverStr, ';');
    std::getline(iss, bronzeStr);

    try {
        gold = std::stoi(goldStr);
        silver = std::stoi(silverStr);
        bronze = std::stoi(bronzeStr);
    } catch (const std::exception& e) {
        std::cerr << "Error parsing medals for " << name << ": " << e.what() << std::endl;
    }

    std::cout << *this << std::endl;
}

// Constructeur de StartWindow
StartWindow::StartWindow(sf::RenderWindow& window) : 
                                                    window(window),
                                                    font(),
                                                    startButton("Random Country", font, 205, 430, 380, 50),
                                                    countryName("", font, 24, 320, 150),
                                                    countryDescription("", font, 20, 240, 200),
                                                    goldMedals("", font, 20, 240, 300),
                                                    silverMedals("", font, 20, 340, 300),
                                                    bronzeMedals("", font, 20, 440, 300),
                                                    currentCountry(),
                                                    flagSprite(),
                                                    flagTexture() {
    window.setFramerateLimit(60); // Limite le taux de rafraîchissement
    window.setVerticalSyncEnabled(false); // Désactive la synchronisation verticale
    if (!font.loadFromFile("Assets/Font.ttf")) { // Charge la police d'écriture pour les textes et les boutons
        throw std::runtime_error("Failed to load font");
    }
    
    // Chargement des données des pays, on affiche le nombre de pays chargés pour s'assurer que la liste est complète
    // 85 pays au total en temps normal
    std::cout << "Loaded " << countries_list.size() << " countries before constructor call." << std::endl;
    loadCountryData();
    std::cout << "Loaded " << countries_list.size() << " countries after constructor call." << std::endl;
}

// Fonction pour charger les données des pays
void StartWindow::loadCountryData() {
    std::ifstream file("Assets/Countries/Country_Details.txt"); // Ouvre le fichier d'informations des pays
    if (!file.is_open()) {
        std::cerr << "Failed to open country details file." << std::endl;
        return;
    }
    std::string line;
    // Lit chaque ligne du fichier et ajoute les informations du pays à la liste
    // Le format de chaque ligne est le suivant: code_du_pays;nom_du_pays;nombre_de_participations;or;argent;bronze
    while (std::getline(file, line)) {
        if (line.empty())
            continue;
        countries_list.push_back(CountryInfo(line)); // Ajoute les informations du pays à la liste
    }
    if (countries_list.empty()) {
        std::cerr << "No country data loaded." << std::endl;
    } else {
        std::cout << "Loaded " << countries_list.size() << " countries." << std::endl;
    }
    file.close();
}

// Fonction pour générer un pays aléatoire
CountryInfo* StartWindow::getRandomCountry() {
    if (countries_list.empty()) { // Vérifie que la liste n'est pas vide
        std::cerr << "Country data is empty." << std::endl;
        return nullptr;
    }

    std::random_device rd;
    std::mt19937 eng(rd());
    std::uniform_int_distribution<> distr(0, countries_list.size() - 1);

    CountryInfo* ret = &countries_list[distr(eng)]; // Sélectionne un pays en utilisant la distribution uniforme aléatoire

    if (ret == currentCountry) {
        std::cout << "Same country as before, new attempt." << std::endl;
        return getRandomCountry(); // Nouvelle tentative si le pays sélectionné est le même que précédemment
    }

    return ret;
}

// Fonction pour afficher les informations d'un pays
void StartWindow::displayCountryInfo() {
    currentCountry = getRandomCountry(); // currentCountry pointe vers un pays aléatoire
    if (!currentCountry) {
        std::cerr << "Failed to get random country." << std::endl;
        return;
    }

    // Recherche la texture du drapeau dans la map ou la charge si elle n'existe pas
    auto it = flagTextures.find(currentCountry->code);
    if (it == flagTextures.end()) {
        sf::Texture texture;
        std::string flagFilePath = "Assets/Countries/Flags/" + currentCountry->code + ".png";
        if (!texture.loadFromFile(flagFilePath)) {
            std::cerr << "Failed to load flag image for " << currentCountry->name << " (" << currentCountry->code << ")" << std::endl;
            return;
        }
        it = flagTextures.insert(it, {currentCountry->code, texture}); // Insère la texture dans la map
    }

    flagSprite.setTexture(it->second);
    flagSprite.setScale(1.0, 1.0);
    flagSprite.setPosition(10, 10);

    // Met à jour les informations affichées du pays
    countryName.setText(currentCountry->name);
    countryDescription.setText("Number of participations : " + currentCountry->description);
    goldMedals.setText("Gold: " + std::to_string(currentCountry->gold));
    silverMedals.setText("Silver: " + std::to_string(currentCountry->silver));
    bronzeMedals.setText("Bronze: " + std::to_string(currentCountry->bronze));
}

// Fonction principale pour exécuter la fenêtre
void StartWindow::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) { // Boucle des événements
            if (event.type == sf::Event::Closed) { // Ferme la fenêtre si le bouton de fermeture est cliqué
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (startButton.isMouseOver(window)) {
                        if (countries_list.empty()) {
                            std::cerr << "Country list is empty in run method." << std::endl;
                            return;
                        }
                        displayCountryInfo(); // Si la liste n'est pas vide, on affiche les informations d'un pays
                    }
                }
            }
        }

        // Affiche les éléments sur la fenêtre
        window.clear(sf::Color::White);
        startButton.draw(window);
        countryName.draw(window);
        countryDescription.draw(window);
        goldMedals.draw(window);
        silverMedals.draw(window);
        bronzeMedals.draw(window);
        if (currentCountry)
            window.draw(flagSprite); // Dessine le sprite du drapeau si un pays est sélectionné
        window.display(); // Affiche la fenêtre mise à jour
    }
}
