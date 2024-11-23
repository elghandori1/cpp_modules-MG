#include "Base.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
    Base* ptr = generate();
    
    identify(ptr);
    identify(*ptr);

    delete ptr;
    
    return 0;
}
