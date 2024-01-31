#include "Application.h"
#include <iostream>

int main() {
    // On lance l'application en vérifiant qu'aucune erreur ne se produit
    try {
        Application app;
        app.run();
    } catch (const std::runtime_error& e) {
        // Si on voit qu'une erreur s'est produite, on l'affiche
        std::cerr << "Une erreur est survenue: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
