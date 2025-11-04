/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:07:00 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/04 16:54:43 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isValidLiteral(const std::string &literal);
static bool isLiteral(const std::string &s);
static bool isSingleChar(const std::string &s);
static bool parseDouble(const std::string &s, double &out);
static void convertChar(const std::string &literal);
static void convertInt(const std::string &literal);
static void convertFloat(const std::string &literal);
static void convertDouble(const std::string &literal);
static void printConversionResults(char c, int i, float f, double d);
static void convertSpecialLiteral(const std::string &literal);

static bool isLiteral(const std::string &s) {
    static const std::string arr[] = {"nan","nanf","+inf","+inff","-inf","-inff","inf","inff"};
    const size_t N = sizeof(arr)/sizeof(arr[0]);
    return std::find(&arr[0], &arr[0] + N, s) != &arr[0] + N;
}

static bool isSingleChar(const std::string &s) {
    return s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]));
}

static bool parseDouble(const std::string &s, double &out) {
    std::string t = s;
    if (t.size() > 1 && t[t.size()-1] == 'f' && t.find('.') != std::string::npos)
        t.erase(t.size()-1);
    char *end = 0;
    out = std::strtod(t.c_str(), &end);
    return (end != t.c_str() && *end == '\0');
}

static bool isValidLiteral(const std::string &literal) {
    if (literal.empty())
        return false;
    if (isSingleChar(literal))
        return std::isprint(static_cast<unsigned char>(literal[0])) != 0; 
    if (isLiteral(literal))
            return true;
    double d;
    return parseDouble(literal, d);
}

static void printConversionResults(char c, int i, float f, double d) {
    std::cout << "char: ";
    if (std::isprint(static_cast<unsigned char>(c)))
    std::cout << "'" << c << "'" << std::endl;
    else
    std::cout << "Non displayable" << std::endl;
    
    std::cout << "int: " << i << std::endl;
    
    std::cout << "float: " << std::fixed
    << std::setprecision((f == static_cast<int>(f)) ? 1 : 6)
    << f << "f" << std::endl;
    std::cout.unsetf(std::ios::fixed);
    
    std::cout << "double: " << std::fixed
    << std::setprecision((d == static_cast<int>(d)) ? 1 : 6)
    << d << std::endl;
    std::cout.unsetf(std::ios::fixed);
}


static void convertSpecialLiteral(const std::string &literal) {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    if (literal == "nan" || literal == "nanf") {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    } else if (literal == "+inf" || literal == "inf" || literal == "+inff" || literal == "inff") {
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    } else if (literal == "-inf" || literal == "-inff") {
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

static void convertChar(const std::string &literal) {
    char c = literal[0];
    int i = static_cast<int>(static_cast<unsigned char>(c));
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    printConversionResults(c, i, f, d);
}

static void convertInt(const std::string &literal) {
    char *end = 0;
    long v = std::strtol(literal.c_str(), &end, 10);
    if (end == literal.c_str() || *end != '\0' || v < INT_MIN || v > INT_MAX) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }
    int i = static_cast<int>(v);
    char c = static_cast<char>(i);
    float f = static_cast<float>(i);
    double d = static_cast<double>(i);
    printConversionResults(c, i, f, d);
}

static void convertFloat(const std::string &literal) {
    double dv;
    if (!parseDouble(literal, dv)) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }
    float f = static_cast<float>(dv);
    char c = static_cast<char>(static_cast<int>(dv));
    int i = static_cast<int>(dv);
    printConversionResults(c, i, f, dv);
}

static void convertDouble(const std::string &literal) {
    double d;
    if (!parseDouble(literal, d)) {
        std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
        return;
    }
    char c = static_cast<char>(static_cast<int>(d));
    int i = static_cast<int>(d);
    float f = static_cast<float>(d);
    printConversionResults(c, i, f, d);
}

void ScalarConverter::convert(const std::string &literal) {
    if (!isValidLiteral(literal)) {
        std::cerr << "Invalid literal: " << literal << std::endl;
        return;
    }
    
    if (isLiteral(literal)) {
        convertSpecialLiteral(literal);
        return;
    }
    
    if (isSingleChar(literal)) {
        convertChar(literal);
        return;
    }
    
    if (literal.size() > 1 && literal[literal.size() - 1] == 'f'
    && literal.find('.') != std::string::npos) {
        convertFloat(literal);
        return;
    }
    
    if (literal.find('.') != std::string::npos) {
        convertDouble(literal);
        return;
    }
    
    convertInt(literal);
}

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter &src) {
    (void)src;
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
    if (this != &rhs) {
    }
    return *this;
}

