#include "RPN.hpp"
#include <sstream>
#include <cctype>

void RPN::printStack() const
{
    std::stack<int> copy = _stack;

    while (!copy.empty())
    {
        std::cout << copy.top() << std::endl;
        copy.pop();
    }
}
void    RPN::evaluate(const std::string& input)
{
    std::stringstream ss(input);
    std::string token;
    int value;
    int rhs = 0;
    int lhs = 0;
    int result = 0;

    while (ss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0]))
        {
            value = token[0] - '0';
            _stack.push(value);
        }
        if (_stack.size() < 2)
            continue ;
        rhs = _stack.top();
        _stack.pop();

        lhs = _stack.top();
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
                if (rhs == '0')
                    std::cerr << "Not divisible by 0" << std::endl;
                else
                    result = lhs / rhs;
                break;
        }
        _stack.push(result);
        std::cout << result << std::endl;
    }
    // math operations

}
