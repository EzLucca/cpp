#include "RPN.hpp"
#include <cctype>
#include <sstream>

bool    RPN::compute(const std::string &token)
{

    long long rhs = _stack.top();
    _stack.pop();
    long long lhs = _stack.top();
    _stack.pop();
    long long result = 0;

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
            if (rhs == 0)
            {
                _stack.push(lhs);
                _stack.push(rhs);
                std::cerr << "Error\n";
                return false;
            }
            result = lhs / rhs;
            break;
        default:
            std::cerr << "Invalid operator\n";
            return false;
    }
    _stack.push(result);
    return true;
}

void RPN::calculate(const std::string &input)
{
    std::stringstream ss(input);
    std::string token;

    while (ss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
        {
            _stack.push(token[0] - '0');
        }
        else if (token == "+" || token == "-" ||
                token == "*" || token == "/")
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error\n";
                return;
            }
            if(!compute(token))
                return;
        }
        else
        {
            std::cerr << "Error\n";
            return;
        }
    }
    if (_stack.size() != 1)
    {
        std::cerr << "Error\n";
        return;
    }
    std::cout << _stack.top() << std::endl;
}
