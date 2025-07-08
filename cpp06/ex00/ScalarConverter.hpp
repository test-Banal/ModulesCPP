#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <typeinfo>
#include <stdexcept>
#include <cctype>
#include <exception>
#include <float.h>

class ScalarConverter {
private:
    // Private member functions to handle different types of conversions
    static void convertChar(const std::string &literal);
    static void convertInt(const std::string &literal);
    static void convertFloat(const std::string &literal);
    static void convertDouble(const std::string &literal);
    static void printConversionResults(char c, int i, float f, double d);
    
    ScalarConverter(); // Default constructor
    ScalarConverter(const ScalarConverter &src); // Copy constructor
    ~ScalarConverter(); // Destructor
    ScalarConverter &operator=(const ScalarConverter &rhs); // Assignment operator


    // Private member function to check if the input is a valid literal
    public:
    static bool isValidLiteral(const std::string &literal);

    static void convert(const std::string const &literal); // Convert function to handle conversion
};   


#endif