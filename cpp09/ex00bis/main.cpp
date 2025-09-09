#include "BitcoinExchange.hpp"

int main()
{
	BitcoinExchange	Test1;

	std::cout << "Test ouverture et lecture fichier .." << std::endl;
	Test1.loadDatabase("data.csv");

	std::cout << "\nDatabase Size : " << Test1.getDatabaseSize() << std::endl;

	return 0;
}
