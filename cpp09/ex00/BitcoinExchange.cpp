#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>

const float BitcoinExchange::kMinValue = 0.0f; //demander dnas le sujet /plus lisible en constante
const float BitcoinExchange::kMaxValue = 1000.0f;

namespace //fonction locale au fichier
{
    std::string trim(const std::string& s)
    {
        std::string::size_type start = 0;
        while (start < s.size() &&
               std::isspace(static_cast<unsigned char>(s[start])))
            ++start;

        std::string::size_type end = s.size();
        while (end > start &&
               std::isspace(static_cast<unsigned char>(s[end - 1])))
            --end;

        return s.substr(start, end - start);
    }
}

BitcoinExchange::BitcoinExchange(const std::string& dbPath) {
    _loadDatabase(dbPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->_database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::_loadDatabase(const std::string& dbPath)
{
    std::ifstream dbFile(dbPath.c_str()); //ouverture fichier =InputFileStream ppour lire dans un fichier text
    if (!dbFile.is_open())
        throw CouldNotOpenFileException();

    std::string line;

    if (!std::getline(dbFile, line)) //on lit la premiere ligne du fichier
        throw InvalidDatabaseException();

    while (std::getline(dbFile, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date;
        std::string priceStr;
        float       price;

        if (std::getline(ss, date, ',') && std::getline(ss, priceStr)) // split apres virgule
        {
            date     = trim(date); //trim pour propreter 
            priceStr = trim(priceStr);

            if (date.empty() || priceStr.empty())
                continue;

            std::stringstream priceSS(priceStr);
            if (priceSS >> price)
            {
                // On pourrait valider la date ici aussi, mais ce n'est pas
                // strictement exigé par le sujet : on suppose la DB correcte.
                _database[date] = price;
            }
        }
    }

    if (_database.empty()) //petit check final
        throw InvalidDatabaseException();
}

bool BitcoinExchange::_isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int  year, month, day;
    char dash1, dash2;
    std::istringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-')
        return false;

    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    return true;
}

float BitcoinExchange::_findExchangeRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
    // lower_bound(date) : Retourne un itérateur sur le premier élément dont la clé est >= date.

    // Date exacte trouvée
    if (it != _database.end() && it->first == date)
        return it->second;

    // Si la date demandée est avant la première date de la DB
    if (it == _database.begin())
        return -1.0f;

    // On prend la date immédiatement inférieure
    --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string& inputPath) const
{
    std::ifstream inputFile(inputPath.c_str());
    if (!inputFile.is_open())
        throw CouldNotOpenFileException();

    std::string line;

    if (!std::getline(inputFile, line))
        return; // fichier vide : rien à faire

    while (std::getline(inputFile, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string datePart;
        std::string valuePart;

        
        if (!std::getline(ss, datePart, '|') || //split apres | 
            !std::getline(ss, valuePart))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date     = trim(datePart); //propreter = enleve espace superflu
        std::string valueStr = trim(valuePart);

        if (date.empty() || valueStr.empty())
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

       
        double value;
        std::stringstream valueSS(valueStr);  // converti en nombre
        if (!(valueSS >> value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Vérifications selon le sujet
        if (!_isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (value < kMinValue)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > kMaxValue)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = _findExchangeRate(date);
        if (rate < 0.0f)
        {
            // Cas où aucune date antérieure ou égale n'existe dans la base
            // L'énoncé ne précise pas le message exact ici, on reste cohérent :
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
    }
}


const char* BitcoinExchange::CouldNotOpenFileException::what() const throw()
{
    return "Error: could not open file.";
}

const char* BitcoinExchange::InvalidDatabaseException::what() const throw()
{
    return "Error: database is empty or invalid.";
}

