#include <iostream>
 #include <vector>
 #include <list>
#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> vec; 
        vec.push_back(10);
        vec.push_back(20);
        vec.push_back(30);
        vec.push_back(40);
        vec.push_back(50);

        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << *it << " : element found " << std::endl;

        std::list<int> lst;
        lst.push_back(5);
        lst.push_back(15);
        lst.push_back(25);

        std::list<int>::iterator list_it = easyfind(lst, 15);
        std::cout << *list_it << " : element found in list" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
