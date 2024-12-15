#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string const &arg) : expression(arg) {}

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::getResult()
{
        if(expression[expression.length()-1] == ' ')
            throw std::runtime_error("Error");

        size_t start = 0;
        while (start < expression.length())
        {
            size_t end = start;
            while (end < expression.length() && expression[end] != ' ')
                end++;

            std::string token = expression.substr(start, end - start);
            if (token.length() == 1 && std::isdigit(token[0]))
                container.push_back(atoi(token.c_str()));

            else if (token.length() == 1 && isOperator(token[0]))
            {
                if (container.size() < 2) {
                    throw std::runtime_error("Error");
                }
                int b = container.back();
                container.pop_back();
                int a = container.back();
                container.pop_back();
                container.clear();
                int result = 0;
                switch (token[0])
                {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': 
                    if (b == 0) 
                        throw std::runtime_error("Error");
                    result = a / b; 
                    break;
                }
                container.push_back(result);
            } else {
               throw std::runtime_error("Error");
            }
           start = end + 1;
          } 

        if (container.size() != 1) {
            throw std::runtime_error("Error");
        }

     std::cout << container.back() << std::endl;
}

RPN::RPN(const RPN &copy){
    (*this) = copy;
}

RPN& RPN::operator=(const RPN &copy) {
    if (this != &copy) {
        container = copy.container;
        expression = copy.expression;
    }
    return *this;
}

RPN::~RPN() {}