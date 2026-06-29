#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
    private:

    public:
        BitcoinExchange() = delete;
        BitcoinExchange(const std::string& file);
        BitcoinExchange(const BitcoinExchange& other) = default;
        BitcoinExchange& operator=(const BitcoinExchange& other) = default;
        ~BitcoinExchange() = default;
};
