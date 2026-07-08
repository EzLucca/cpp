#pragma once
#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<int> _stack;

    public:
        void    calculate(const std::string& expression);
        void    compute(const std::string &token);
};
