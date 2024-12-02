#include <iostream>
#include "Array.hpp"

int main()
{
// Test default constructor
    Array<int> a1;
    std::cout << "Size of a1: " << a1.size() << std::endl;

    // Test constructor with parameter
    Array<int> a2(5);
    std::cout << "Size of a2: " << a2.size() << std::endl;
    for (unsigned int i = 0; i < a2.size(); ++i) {
        std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
    }

    // Test copy constructor
    Array<int> a3(a2);
    std::cout << "Size of a3: " << a3.size() << std::endl;
    for (unsigned int i = 0; i < a3.size(); ++i) {
        std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
    }

    // Test assignment operator
    Array<int> a4;
    a4 = a2;
    std::cout << "Size of a4: " << a4.size() << std::endl;
    for (unsigned int i = 0; i < a4.size(); ++i) {
        std::cout << "a4[" << i << "] = " << a4[i] << std::endl;
    }

    // Test out of bounds access
    try {
        std::cout << "a2[10] = " << a2[10] << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    //reading only if the instance is const 

    const Array<int> aa(2);

    /*
    aa[0]=11111; //error because read-only
    for(unsigned int i =0; i <aa.size();i++){
       std::cout << "aa[" << i << "] = " << aa[i] << std::endl; 
    }
    */

    return 0;
}
