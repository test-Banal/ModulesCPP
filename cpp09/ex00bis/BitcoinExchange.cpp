#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	// Constructeur par defaut
}
BitcoinExchange::~BitcoinExchange() {
	// Destructeur
}


std::string BitcoinExchange::trim(const std::string &str) {
	size_t start = str.find_first_not_of("\t\r\n");
	if (start == std::string::npos)
		return "";
	size_t end = str.find_last_not_of("\t\r\n");
	return str.substr(start, end - start + 1);
}

double BitcoinExchange::parseDoubleStrict(const std::string &str) {
	if (str.empty()) 
		return -1;

	char *endptr;
	double result = std::strtod(str.c_str(), &endptr);
	if (*endptr != '\0')
		return -1;

	return result;
}
bool BitcoinExchange::validDate(const std::string &date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    // Vérifier que les positions attendues sont bien des chiffres
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || year > 2023)
        return false;
    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {
        31, 
        (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 29 : 28, 
        31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}


void BitcoinExchange::loadDatabase(const std::string &csvFile) {
	std::ifstream file(csvFile.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open database file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;
	while (std::getline(file, line)) {
		//ignore la premiere ligne
		if (firstLine) {
			firstLine = false;
		continue;
		}

		//ignore les lignes vides
		if (trim(line).empty()) 
			continue;

		//cherche la virgule separatrice dans data.csv
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos) {
			std::cerr << "Error: bad database format => " << line << std::endl;
			continue;
		}

		//extrait la date et le taux dans data.csv
		std::string dateStr = trim(line.substr(0, commaPos));
		std::string rateStr = trim(line.substr(commaPos + 1));
	
		//Parse le taux 
		double rate = parseDoubleStrict(rateStr);
		if (rate < 0) {
			std::cerr << "Error: invalid rate in database => " << rateStr << std::endl;
			continue;
		}

		//stocker dans la map (tri automatiquement)
		rates[dateStr] = rate;
	}

	file.close();

	//affichage bug
	std::cout << "Database loaded: " << rates.size() << " entries" << std::endl;

	if (!rates.empty()) {
		std::cout << "First entry: " << rates.begin()->first << " => " << rates.begin()->second << std::endl;
		std::map<std::string, double>::reverse_iterator lastIt = rates.rbegin();
		std::cout << "Last entry: " << lastIt->first << "=> " << lastIt->second<< std::endl;
	}
}
	



