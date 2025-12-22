/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 19:11:14 by aneumann          #+#    #+#             */
/*   Updated: 2025/12/22 20:45:01 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <exception>

class BitcoinExchange
{
private:
    BitcoinExchange();
    std::map<std::string, float> _database;

    void  _loadDatabase(const std::string &dbPath);
    bool  _isValidDate(const std::string &date) const;
    float _findExchangeRate(const std::string &date) const;

public:
    explicit BitcoinExchange(const std::string &dbPath);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange& operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void processInputFile(const std::string &inputPath) const;

    static std::string trim(const std::string &s);

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
