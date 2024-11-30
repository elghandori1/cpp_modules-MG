#include "iter.hpp"

int main(){
  int intArray[] = {1, 2, 3, 4, 5};

  std::cout << "Array:" << std::endl;
  iter(intArray, 5, printElement<int>);

  std::cout << "using the increment:" << std::endl; 
  iter(intArray, 5, increment<int>);
  iter(intArray, 5, printElement<int>);

  return (0);
}
