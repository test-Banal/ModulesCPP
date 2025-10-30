#ifndef SCARLARCONVERTER_HPP
#define SCARLARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class ScalarConverter {
private:
    static void convertChar(const std::string &literal);
    static void convertInt(const std::string &literal);
    static void convertFloat(const std::string &literal);
    static void convertDouble(const std::string &literal);
    static void printConversionResults(char c, int i, float f, double d);
    
    ScalarConverter(); 
    ScalarConverter(const ScalarConverter &src); 
    ~ScalarConverter(); 
    ScalarConverter &operator=(const ScalarConverter &rhs); 

    public:
    static bool isValidLiteral(const std::string &literal);
    static void convertSpecialLiteral(const std::string &literal);
    static void convert(const std::string &literal);
};   


#endif