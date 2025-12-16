#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map> //premier container
#include <string>
#include <exception>

class BitcoinExchange
{
private:
    //container map : ordonne par cle =  par date (en string), et float pour le taux
    std::map<std::string, float> _database;

    // Limites imposées par le sujet : “j’ai mis les bornes min/max dans des
    //constantes statiques pour centraliser la logique et rendre le code plus lisible.”
    static const float kMinValue;
    static const float kMaxValue;

    void  _loadDatabase(const std::string& dbPath);
    bool  _isValidDate(const std::string& date) const;
    float _findExchangeRate(const std::string& date) const;

public:
    //Je veux qu’un BitcoinExchange soit toujours valide et initialisé avec une base de données, donc je force la construction avec un dbPath.”
    //voir si pas ajoute un constructeur par defaut dans private ????
    explicit BitcoinExchange(const std::string& dbPath);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    // Traite le fichier d'entrée "date | value"
    void processInputFile(const std::string& inputPath) const;

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

