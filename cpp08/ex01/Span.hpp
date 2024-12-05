#include <iostream>
#include<algorithm>
#include <vector>

class Span
{
	private:
		std::vector<int> numbers;
		unsigned int size;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &copy);
		void addNumber(int N);
        int shortestSpan();
		int longestSpan();
		Span &operator=(const Span &copy);
		~Span();
		template <typename T> 
		void addNumbers(T begin, T end)
		{
			if (std::distance(begin, end) + numbers.size() <= size)
			{ 
				numbers.insert(numbers.end(), begin, end);
			}
			else
			{
				throw std::out_of_range("Span cannot hold all these elements!");
			}
		}
};
