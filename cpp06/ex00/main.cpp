#include"ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string input = av[1];
        ScalarConverter::convert(input);
    }else
    {
        std::cout <<"Usage: <program> <value>\n"; 
    }
    return 0;
}