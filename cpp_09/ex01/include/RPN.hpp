#pragma once
#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<long long> _stack;

    public:
        void    calculate(const std::string& expression);
        bool    compute(const std::string &token);
};
