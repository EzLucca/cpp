#include "RPN.hpp"
#include <iostream>

char *s;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./RPN \"expression\"\n";
        return 1;
    }

    RPN calculator;
    calculator.calculate(argv[1]);
}
