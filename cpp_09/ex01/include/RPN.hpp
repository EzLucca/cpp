#pragma once
#include <iostream>
#include <stack>

class RPN
{
    private:
        std::stack<int> _stack;

    public:
        void evaluate(const std::string& expression);

        void    printStack() const;
};
