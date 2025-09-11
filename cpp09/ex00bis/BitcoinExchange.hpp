#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <stdio.h>

class BitcoinExchange {
	private:
		std::map<std::string, double> rates;

		std::string trim(const std::string &str);
		public:
		BitcoinExchange();					//constructeur
		~BitcoinExchange();			        	//destructeur
		BitcoinExchange &operator=(const BitcoinExchange rhs); //op affectation
		BitcoinExchange(const BitcoinExchange &src);			       //constructeur copie

		//parsing files
		bool validDate(const std::string &date) const;
		double parseDoubleStrict(const std::string &str);

		//charger Data dans stl
		void loadDatabase(const std::string &csvFile);		//fct ouvrir fichier
		
		//chercher taux par date
		//double getRateForDate(const std::string &date) const;
		
		// getters (peut etre supprimer a la fin)
		size_t getDatabaseSize() const { return rates.size();}
};

#endif
