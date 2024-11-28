#pragma once
#include <iostream>

template <typename T, typename F>

void iter(T* array, size_t length, F func)
{ 
    for (size_t i = 0; i < length; i++)
    {
        func(array[i]);
    }

}

template <typename T> 

void printElement(const T& element)
{ 
    std::cout << element << std::endl;
}

template <typename T>

void increment(T& elm){
    elm+=1;
}