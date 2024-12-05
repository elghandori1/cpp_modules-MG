#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
    std::srand(std::time(0));
    
    try {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

        std::vector<int> more_numbers;
        for (int i = 0; i < 5; i++){
            more_numbers.push_back(rand() % 10);
            std::cout << more_numbers[i] << " | ";
        }
        std::cout << std::endl;

        Span sp2 = Span(5);
        sp2.addNumbers(more_numbers.begin(), more_numbers.end());

        std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;

    } catch (const std::exception &e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}