#include "Bureaucrat.hpp"

int main()
{ 
    try
    {
        Bureaucrat B("mohammed", 2);

        std::cout << B <<std::endl;
        B.increment();
        std::cout << B <<std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "Finish" << std::endl;
}
