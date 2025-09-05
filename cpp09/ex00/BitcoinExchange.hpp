#ifndef "BITCOINEXCHANGE_HPP"
#define "BITCOINEXCHANGE_HPP"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <map>

class BitcoinExchange {
	private:
		//container stock date + valeur

	public:
		BitcoinExchange(); //constructeur par defaut
		BitcoinExchange(const BitcoinExchange &other);//constructeur de copie
		BitcoinExchange &operator=(const BitcoinExchange &other);//operateur d'assignation
		~BitcoinExchange(); //destructeur

		
