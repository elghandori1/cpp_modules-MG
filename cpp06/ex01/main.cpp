#include <iostream>
#include "Serializer.hpp"

int main(){

  Data ptrdata = {10,"hello"};

  std::cout <<"Values: " <<ptrdata.intValue << " - " 
            << ptrdata.stringValue <<"\n";

  uintptr_t unitptr = Serializer::serialize(&ptrdata);

  std::cout <<"The unitptr: " <<unitptr <<"\n";
  std::cout << "Data Address: " <<&ptrdata << "\n";

  Data* deserializedData = Serializer::deserialize(unitptr);
  std::cout << "Deserialized Data Address: " << deserializedData <<"\n";

  if (deserializedData == &ptrdata) {
        std::cout << "Deserialization are working correctly!\n";
    } else {
        std::cout << "Something went wrong!\n";
    }

   std::cout <<"Values : " <<deserializedData->intValue << " - " 
             << deserializedData->stringValue <<"\n";
             
    return 0;
}
