#include "Base.hpp"
#include <cstdlib>
#include <iostream>

Base::~Base(){}

Base* generate()
{
    srand(time(0));
    int randomChoice = rand() % 3;
    
    if (randomChoice == 0) 
    {
        return new A();
    }
    else if (randomChoice == 1) 
    {
        return new B();
    }
    else {
        return new C();
    }
}

void identify(Base* p)
{
    Base *tmp;
    tmp=dynamic_cast<A*>(p);

    if (tmp != NULL)
    {     
        std::cout << "the object pointed: \"A\"" <<std::endl;
        return ;
    }
    tmp = dynamic_cast<B*>(p);
    if (tmp != NULL)
    {    
         std::cout << "the object pointed: \"B\"" <<std::endl;
         return ;
    }
    tmp = dynamic_cast<C*>(p);
    if (tmp != NULL)
    {    
         std::cout << "the object pointed: \"C\"" <<std::endl;
         return ;
    }
    std::cout << "Unknown :("<<std::endl;
}

void identify(Base& p)
{
    Base tmp;
    try {
        tmp = dynamic_cast<A &>(p);
        std::cout << "the ref object pointed: \"A\"" <<std::endl;
    } catch (...)
    {
        try {
             tmp = dynamic_cast<B &>(p);
             std::cout << "the ref object pointed: \"B\"" <<std::endl;
        } 
        catch (...)
        {
            try {
                tmp = dynamic_cast<C &>(p);
                 std::cout << "the ref object pointed: \"C\"" <<std::endl;
            } catch (...) {
                std::cout << "Unknown :(" << std::endl;
            }
        }
    }
}
