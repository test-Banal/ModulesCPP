#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

class BitcoinExchange {
	private:
		//container stock date + valeur
		std::map<std::string, double> dataBase;


	public:
		BitcoinExchange(); //constructeur par defaut
		BitcoinExchange(const BitcoinExchange &other);//constructeur de copie
		BitcoinExchange &operator=(const BitcoinExchange &other);//operateur d'assignation
		~BitcoinExchange(); //destructeur

		void readDataBase(std::string fileName);
		void readInput(std::string fileName);
		bool isDateValid(const std::string &date);
		bool isValueValid(const std::string &value);
		void processLine(const std::string &line);
		double getExchangeRate(const std::string &date);
};
	
#endif