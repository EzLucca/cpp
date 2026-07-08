#include "RPN.hpp"
#include <iostream>

char *s;

int main(int argc, char **argv)
{
    if(argc != 2)
        return(1);
    
    RPN calculator;
    calculator.calculate(argv[1]);
}
