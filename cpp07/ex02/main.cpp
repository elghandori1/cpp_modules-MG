#include <iostream>
#include "Array.hpp"

int main()
{
    Array<int> a1;
    std::cout << "Size of a1: " << a1.size() << std::endl;
    
    Array<int>a2(5);
    std::cout << "Size of a2: " << a2.size() << std::endl;
    for(unsigned int i =0; i <a2.size();i++){
       std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
    }

    try {
        std::cout << "a2[10] = " << a2[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
