/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:11:45 by aneumann          #+#    #+#             */
/*   Updated: 2025/12/22 20:51:34 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream> //stl
#include <fstream> //isopen
#include <sstream> //stringstream
#include <cctype> //isspace


std::string BitcoinExchange::trim(const std::string &s)
{
    size_t start = 0;
    while (start < s.size() &&
           std::isspace(static_cast<unsigned char>(s[start])))
        ++start;

    size_t end = s.size();
    while (end > start &&
           std::isspace(static_cast<unsigned char>(s[end - 1])))
        --end;

    return s.substr(start, end - start);
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
    std::ifstream dbFile(dbPath.c_str());
    if (!dbFile.is_open())
        throw CouldNotOpenFileException();

    std::string line;

    if (!std::getline(dbFile, line))
        throw InvalidDatabaseException();

    while (std::getline(dbFile, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string date;
        std::string priceStr;
        float       price;

        if (std::getline(ss, date, ',') && std::getline(ss, priceStr))
        {
            date     = trim(date);
            priceStr = trim(priceStr);

            if (date.empty() || priceStr.empty())
                continue;

            std::stringstream priceSS(priceStr); 
            if (priceSS >> price)             
            {
                _database[date] = price; 
            }
        }
    }

    if (_database.empty()) 
        throw InvalidDatabaseException();
}

bool BitcoinExchange::_isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    char dash1, dash2;
    std::istringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-')
        return false;

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = {
        31,
        28,
        31,
        30,
        31, 
        30, 
        31,
        31,
        30,
        31,
        30,
        31  
    };

    bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (leap)
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

float BitcoinExchange::_findExchangeRate(const std::string& date) const
{
    std::map<std::string, float>::const_iterator it = _database.lower_bound(date);

    if (it != _database.end() && it->first == date) 
        return it->second; 

    if (it == _database.begin())
        return -1.0f;

    --it;
    return it->second;
}

void BitcoinExchange::processInputFile(const std::string &inputPath) const
{
    std::ifstream inputFile(inputPath.c_str());
    if (!inputFile.is_open())
        throw CouldNotOpenFileException();

    std::string line;

    if (!std::getline(inputFile, line))
        return;

    while (std::getline(inputFile, line))
    {
        if (line.empty())
            continue;

        std::stringstream ss(line);
        std::string datePart;
        std::string valuePart;

        
        if (!std::getline(ss, datePart, '|') || !std::getline(ss, valuePart))  
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date     = trim(datePart);
        std::string valueStr = trim(valuePart);

        if (date.empty() || valueStr.empty())
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

       
        double value;
        std::stringstream valueSS(valueStr);
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
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        float rate = _findExchangeRate(date);
        if (rate < 0.0f)
        {
            std::cerr << "Error: bad input or before creation btc => " << date << std::endl;
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

