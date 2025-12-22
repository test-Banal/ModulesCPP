#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map> // container
#include <string>
#include <exception> //what throw execption

class BitcoinExchange
{
private:
    BitcoinExchange();
    std::map<std::string, float> _database;
    
    static const float kMinValue;
    static const float kMaxValue;

    void  _loadDatabase(const std::string &dbPath);
    bool  _isValidDate(const std::string &date) const;
    float _findExchangeRate(const std::string &date) const;

public:
    explicit BitcoinExchange(const std::string &dbPath);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange& operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void processInputFile(const std::string &inputPath) const;

    class CouldNotOpenFileException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class InvalidDatabaseException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#endif