#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void)copy;
    return (*this);
}

bool ScalarConverter::pars_1(std::string &literal, char flag) 
{ 
    size_t i = 0;
    int point = 0;
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    while (i < literal.length())
    { 
        if (isdigit(literal[i]))
        { i++; } 
        else if (literal[i] == '.')
        { 
            i++; point++; 
        } 
        else { 
            break; 
        }
    }
    if (point == 1 && ((flag == 'f' && literal[i] == 'f' && literal[i + 1] == '\0') ||
        (flag == 'd' && literal[i] == '\0')))
        {
          return true;
        }
        return false;
}

bool ScalarConverter::pars_2(std::string &literal)
{
    size_t i = 0;
    
    if (literal[0] == '-' || literal[0] == '+')
        i++;
    
    while (i < literal.length())
    {
        if (!isdigit(literal[i]))
            return false;
        i++;
    }
    return true;
}

void ScalarConverter::is_float(std::string &prompt)
{
    int in = atoi(prompt.c_str());
    float fl = atof(prompt.c_str());
    double dob = static_cast<double>(fl);
    char ch = static_cast<char>(in);
    
    if (!isascii(in))
        std::cout << "Char out of ASCII Table" << std::endl;
    else if (isprint(ch))
        std::cout << "Char : '" << ch << "'" << std::endl;
    else if (prompt == "-inff" || prompt == "+inff" || prompt == "nanf")
        std::cout << "Char: impossible" << std::endl;
    else
        std::cout << "Char: Not displayable" << std::endl;
    
    if (prompt == "-inff" || prompt == "+inff" || prompt == "nanf")
        std::cout << "Int : impossible" << std::endl;
    else
        std::cout << "Int : " << in << std::endl;
    
    std::cout << std::fixed << std::setprecision(1) << "float: " << fl << "f\n";
    std::cout << "double : " << dob << std::endl;
}

void ScalarConverter::is_double(std::string &prompt)
{
    int in = atoi(prompt.c_str());
    double dob = atof(prompt.c_str());
    float fl = static_cast<float>(dob);
    char ch = static_cast<char>(in);
    
    if (!isascii(in))
        std::cout << "Char out of ASCII Table" << std::endl;
    else if (isprint(ch))
        std::cout << "Char : '" << ch << "'" << std::endl;
    else if (prompt == "-inf" || prompt == "+inf" || prompt == "nan")
        std::cout << "Char: impossible" << std::endl;
    else
        std::cout << "Char: Not displayable" << std::endl;
    
    if (prompt == "-inf" || prompt == "+inf" || prompt == "nan")
        std::cout << "Int : impossible" << std::endl;
    else
        std::cout << "Int : " << in << std::endl;
    
    std::cout << std::fixed << std::setprecision(1) << "float: " << fl << "f\n";
    std::cout << "double : " << dob << std::endl;
}

void ScalarConverter::is_int(std::string &prompt)
{
    long long in = atoll(prompt.c_str());
    double dob = static_cast<double>(in);
    float fl = static_cast<float>(in);
    char ch = static_cast<char>(in);
    
    if (!isascii(in))
        std::cout <<  "Char out of ASCII Table" << std::endl;
    else if (isprint(ch))
        std::cout << "Char : '" << ch << "'" << std::endl;
    else
        std::cout << "Char: Not displayable" << std::endl;
    
    if (in > INT_MAX || in < INT_MIN)
        std::cout << "Int : Out of integer range!" << std::endl;
    else
        std::cout << "Int : " << static_cast<int>(in) << std::endl;
    
    std::cout << std::fixed << std::setprecision(1) << "float: " << fl << "f\n";
    std::cout << "double : " << dob << std::endl;   
}

void ScalarConverter::is_char(const std::string &prompt)
{ 
    int in = static_cast<int>(prompt[0]);
    double dob = static_cast<double>(prompt[0]);
    float fl = static_cast<float>(prompt[0]);
    
    std::cout << "Char : '" << prompt[0]  << "'" << std::endl;
    std::cout << "Int : " << in << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "float: " << fl << "f\n";
    std::cout << "double : " << dob << std::endl;
}

void ScalarConverter::convert(std::string propmt)
{
    if (pars_1(propmt,'f') || propmt == "-inff" || propmt == "+inff" || propmt == "nanf")
        is_float(propmt);
    else if (pars_1(propmt,'d') || propmt == "-inf" || propmt == "+inf" || propmt == "nan")
        is_double(propmt);
    else if (pars_2(propmt))
        is_int(propmt);
    else if(!isdigit(propmt[0]) && propmt.length() == 1)
        is_char(propmt);
    else
        std::cout << "Conversion not possible" << std::endl;
}
