#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {
    // Default constructor
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    // Copy constructor
    (void)src; // Avoid unused parameter warning
}

ScalarConverter::~ScalarConverter() {
    // Destructor
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
    // Assignment operator
    if (this != &rhs) {
    }
    return *this;
}

bool ScalarConverter::isValidLiteral(const std::string &literal) {
    // Check if the literal is a valid scalar type representation
    if (literal.empty()) return false;

    // Check for char literals
    if (literal.length() == 1 && std::isprint(literal[0])) return true;

    // Check for int, float, and double literals
    try {
       std::strtod(literal.c_str(), NULL); // Try to convert to double
        return true;
    } catch (const std::invalid_argument &) {
        return false; // Not a valid number
    } catch (const std::out_of_range &) {
        return false; // Out of range
    }
}
void ScalarConverter::convert(const std::string &literal) {
    if (!isValidLiteral(literal)) {
        std::cerr << "Invalid literal: " << literal << std::endl;
        return;
    }

    // Cas spéciaux (nan, inf...)
    if (literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "+inff" ||
        literal == "-inf" || literal == "-inff") {
        convertSpecialLiteral(literal);
        return;
    }

    // Cas char (non chiffre, caractère imprimable unique)
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        convertChar(literal);
        return;
    }

    // Cas float (finissant par 'f' mais pas les cas spéciaux)
if (literal[literal.length() - 1] == 'f' && literal.find('.') != std::string::npos){
        convertFloat(literal);
        return;
    }

    // Cas double (contient un point mais pas 'f')
    if (literal.find('.') != std::string::npos) {
        convertDouble(literal);
        return;
    }

    // Cas int (pas de point ni 'f')
    convertInt(literal);
}

void ScalarConverter::convertChar(const std::string &literal) {
    char c = literal[0];
    int i = static_cast<int>(c);
    float f = static_cast<float>(c);
    double d = static_cast<double>(c);

    printConversionResults(c, i, f, d);
}

void ScalarConverter::convertInt(const std::string &literal) {
    int i = static_cast<int>(std::strtol(literal.c_str(), NULL, 10));
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);

    printConversionResults(c, i, f, d);
}

void ScalarConverter::convertFloat(const std::string &literal) {
    float f = std::strtof(literal.c_str(), NULL);
    char c = static_cast<char>(f);
    int i = static_cast<int>(f);
    double d = static_cast<double>(f);

    printConversionResults(c, i, f, d);
}

void ScalarConverter::convertDouble(const std::string &literal) {
    double d = std::strtod(literal.c_str(), NULL);
    char c = static_cast<char>(d);
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);

    printConversionResults(c, i, f, d);
}

void ScalarConverter::printConversionResults(char c, int i, float f, double d) {
    std::cout << "char: ";
    if (std::isprint(c)) {
        std::cout << "'" << c << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }

    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}


void ScalarConverter::convertSpecialLiteral(const std::string &literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (literal == "+inf" || literal == "+inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}