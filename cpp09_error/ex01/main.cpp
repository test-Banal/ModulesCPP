#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    try {
        int result = RPN::evaluate(argv[1]);//ALGO
        std::cout << result << std::endl;//si tout ok  affiche resultat
    } catch (const std::exception &e) {
        (void)e; // ignore le message détaillé pour ne pas polluer la sortie car tjrs e avec methode catch mais ici on demande que "Error"
        std::cerr << "Error" << std::endl; //msg erreur (parsing, operateur invalide, div / 0, etc)
        return 1;
    }

    return 0;
}