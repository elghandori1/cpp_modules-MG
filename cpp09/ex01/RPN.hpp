#include <stack>
#include <string>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class RPN
{
	private:
		std::stack<int> container;
		std::string expression;
	public:
		RPN();
		RPN(std::string arg);
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();
		bool isOperator(char c);
		void getResult();
};