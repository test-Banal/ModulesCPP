#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <cstdlib>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, double> rates;

		std::string trim(const std::string &str);
		double parseDoubleStrict(const std::string &str);
	public:
		//BitcoinExchange();					//constructeur
		//~BitcoinEchange();			        	//destructeur
		//BitcoinExchange &operator=(const BitcoinExchange rhs); //op affectation
		//BitcoinExchange(const BitcoinExchange &src);			       //constructeur copie
		void loadDatabase(const std::string &csvFile);		//fct ouvrir fichier
		size_t getDatabaseSize() const { return rates.size();} //getter
		
		//bool validDate(const std::string &date) const;
		//double getRateForDate(const std::string &date) const;
		
};

#endif
