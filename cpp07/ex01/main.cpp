#include "iter.hpp"

int main()
{
  int intArray[] = {1, 2, 3, 4, 5};
  double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};

  std::cout << "Integer Array:" << std::endl;
  iter(intArray, 5, printElement<int>);

  std::cout << "using the increment:" << std::endl; 
  iter(intArray, 5, increment<int>);
  iter(intArray, 5, printElement<int>);

  std::cout << "Double Array:" << std::endl; 
  iter(doubleArray, 5, printElement<double>);

  return (0);
}
