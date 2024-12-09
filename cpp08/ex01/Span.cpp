#include "Span.hpp"

Span::Span()
{
	size = 5;
}

Span::Span(unsigned int N) : size(N) {}

void Span::addNumber(int num)
{
     if (numbers.size() >= size)
     { 
        throw std::out_of_range("Span is already full"); 
     } 
     numbers.push_back(num);
}

int Span::shortestSpan() 
{ 
    if (numbers.size() < 2) 
    { 
        throw std::out_of_range("Not enough numbers to find a span"); 
    } 
    std::vector<int> sorted_numbers = numbers; 
    std::sort(sorted_numbers.begin(), sorted_numbers.end()); 
    int shortest = sorted_numbers[1] - sorted_numbers[0]; 
    for (size_t i = 1; i < sorted_numbers.size() - 1; i++)
    {   
        int span = sorted_numbers[i + 1] - sorted_numbers[i]; 
        if (span < shortest) 
        { 
            shortest = span; 
        } 
    }
    return shortest; 

}

int Span::longestSpan()
{
    if (numbers.size() < 2) 
    { 
        throw std::out_of_range("Not enough numbers to find a span");
    }

    int max = *std::max_element(numbers.begin(), numbers.end());
	int min = *std::min_element(numbers.begin(), numbers.end());

    return (max - min);
}

Span::Span(const Span &copy)
{
	(*this) = copy;
}

Span &Span::operator=(const Span &copy)
{
	size = copy.size;
	numbers = copy.numbers;
	return (*this);
}

Span::~Span(){}
