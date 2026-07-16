#include "RPN.hpp"
#include <cctype>
#include <sstream>

void    RPN::compute(const std::string &token)
{

    long long result = 0;
    long long rhs = _stack.top();
    _stack.pop();
    long long lhs = _stack.top();
    _stack.pop();

    switch (token[0])
    {
        case '+':
            result = lhs + rhs;
            break;
        case '-':
            result = lhs - rhs;
            break;
        case '*':
            result = lhs * rhs;
            break;
        case '/':
            if (rhs == 0) {
                std::cerr << "Division by zero\n";
                return;
            }
            result = lhs / rhs;
            break;
        default:
            std::cerr << "Invalid operator\n";
            return;
    }

    _stack.push(result);
}

void RPN::calculate(const std::string &input) {
    std::stringstream ss(input);
    std::string token;
    std::string operation;

    while (ss >> token) {
        if (token.size() == 1 && std::isdigit(token[0])) 
        {
            _stack.push(token[0] - '0');
            continue;
        }
        if (_stack.size() < 2 )
        {
            std::cerr << "Error: insufficient operands\n";
            return;
        }

        compute(token);
    }
    if (_stack.size() != 1) {
        std::cerr << "Invalid RPN expression\n";
        return;
    }
    std::cout << _stack.top() << std::endl;
}
