#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	(void)argv; //car pour linstant pas input.txt dans les tests, donc a enlever par la suite
	if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

	//if(!valid) //cad si argv bien parsing

    BitcoinExchange exchange;
    
    // Charger la base de données
    exchange.loadDatabase("data.csv");

	return 0;
}
