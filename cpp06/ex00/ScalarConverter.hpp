#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>

class ScalarConverter 
{
public:
    static void convert(std::string literal);
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &copy);
    ~ScalarConverter();
    static bool pars_1(std::string &literal,char flag);
    static bool pars_2(std::string &literal);
    static void is_float(std::string &prompt);
    static void is_double(std::string &prompt);
    static void is_int(std::string &prompt);
    static void is_char(const std::string &prompt);
};

#endif
