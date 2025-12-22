#include "BitcoinExchange.hpp"

#include <iostream> //stl
#include <fstream> //isopen
#include <sstream> //stringstream
#include <cctype> //isspace

const float BitcoinExchange::kMinValue = 0.0f; //demander dnas le sujet /plus lisible en constante
const float BitcoinExchange::kMaxValue = 1000.0f;

namespace //fonction locale au fichier
{
    std::string trim(const std::string &s) //trim qui enleve white space ?
    {
        std::string::size_type start = 0;
        while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) //rapelle pourquoi static cast<unsigned char> ?
            ++start;

        std::string::size_type end = s.size();
        while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
            --end;

        return s.substr(start, end - start);
    }
}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &dbPath) {
    _loadDatabase(dbPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        this->_database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::_loadDatabase(const std::string &dbPath)
{
    std::ifstream dbFile(dbPath.c_str()); //ouverture fichier =InputFileStream ppour
    // lire dans un fichier text
    if (!dbFile.is_open())
        throw CouldNotOpenFileException();

    std::string line;

    if (!std::getline(dbFile, line)) //on lit la premiere ligne du fichier
        throw InvalidDatabaseException();

    while (std::getline(dbFile, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line); //ss chaine en gros de token grace a stringstream
        std::string date;
        std::string priceStr;
        float       price;

        if (std::getline(ss, date, ',') && std::getline(ss, priceStr)) // split apres virgule
        {
            date     = trim(date); //trim pour propreter 
            priceStr = trim(priceStr);

            if (date.empty() || priceStr.empty())
                continue;

            std::stringstream priceSS(priceStr); //transforme string en flux puis 
            if (priceSS >> price)               // puis ici en float = transfert, si reussi , on met dans la map
            {
                _database[date] = price; //ici quoon fait notre container final map avec date et prix
            }
        }
    }

    if (_database.empty()) //petit check final
        throw InvalidDatabaseException();
}

bool BitcoinExchange::_isValidDate(const std::string &date) const
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

    if (it != _database.end() && it->first == date) //date exacte trouvee
        return it->second; 

    if (it == _database.begin()) //pas trouve
        return -1.0f;

    --it; //si pas trouve exacte : la date la plus proche
    return it->second;
}
//first/second vient stl : cle/valeur

void BitcoinExchange::processInputFile(const std::string &inputPath) const
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

        
        if (!std::getline(ss, datePart, '|') || !std::getline(ss, valuePart)) //split apres | 
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

