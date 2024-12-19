#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string arg) : expression(arg) {}

bool RPN::isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::getResult()
{
    size_t i = 0;
    while (i < expression.length())
    {
        while (i < expression.length() && std::isspace(expression[i]))
            i++;

        if (i >= expression.length())
            break;

        size_t j = i;
        while (j < expression.length() && !std::isspace(expression[j]))
            j++;

        std::string token = expression.substr(i, j - i);
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
        i = j;
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