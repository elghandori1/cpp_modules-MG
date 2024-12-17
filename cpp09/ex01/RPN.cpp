#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string const &arg) : expression(arg) {}

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::getResult()
{
    size_t start = 0;
    while (start < expression.length())
    {
        // Skip leading spaces
        while (start < expression.length() && std::isspace(expression[start]))
            start++;

        if (start >= expression.length())
            break;

        size_t end = start;
        while (end < expression.length() && !std::isspace(expression[end]))
            end++;

        std::string token = expression.substr(start, end - start);
        if (token.length() == 1 && std::isdigit(token[0]))
            container.push(atoi(token.c_str()));

        else if (token.length() == 1 && isOperator(token[0]))
        {
            if (container.size() < 2) {
                throw std::runtime_error("Error");
            }
            int b = container.top();
            container.pop();
            int a = container.top();
            container.pop();
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
            container.push(result);
        } else {
           throw std::runtime_error("Error");
        }
        
        start = end;
    } 

    if (container.size() != 1) {
        throw std::runtime_error("Error");
    }

    std::cout << container.top() << std::endl;
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