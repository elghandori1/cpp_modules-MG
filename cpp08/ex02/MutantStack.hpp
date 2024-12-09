#include<iostream>
#include<deque>
#include<stack>
#include<vector>
#include<list>

template <typename T, typename Container= std::deque<T> >

class MutantStack: public std::stack<T, Container>
{
	public:
		typedef typename std::stack<T, Container>::container_type::iterator iterator;

		MutantStack(){};

		MutantStack(MutantStack const &copy):std::stack<T, Container>(copy)
		{
			(*this) = copy;
		}

		MutantStack &operator=(MutantStack const &copy)
		{
			this->c = copy.c;
			return (*this);
		}

		iterator begin()
		{
			return this->c.begin();
		};

		iterator end(){
			return this->c.end();
			
		};

		~MutantStack(){};
};	

