#include "Bureaucrat.hpp"

int main()
{ 
    try
    {
        Bureaucrat a("mohammed", 2);
        std::cout << a <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Finish" << std::endl;
}