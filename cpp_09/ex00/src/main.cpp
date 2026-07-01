#include "BitcoinExchange.hpp"
#include <iostream>

// int main (int argc, char **argv)
// {
//     if(argc != 2)
//     {
//         std::cout << "Usage : ./btc input.txt" << std::endl;
//         return 1;
//     }
//     // validate the argv
//
//     BitcoinExchange btc(argv[1]);
//
//     try {
//         btc.execute();
//     }
//     catch (std::exception &e)
//     {
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }
//
//     return 0;
// }

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;

    if (!btc.loadDataBase("data.csv")) {
        std::cerr << "Error: could not open database." << std::endl;
        return 1;
    }

    btc.processInput(argv[1]);
    return 0;
}
