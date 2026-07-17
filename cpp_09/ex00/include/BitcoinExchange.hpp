#pragma once

#include <map>
#include <string>
#include <cmath>
#include <cctype>
#include <chrono>

class BitcoinExchange
{
    private:
        std::string _dataBase;
        std::map<std::string, float> _dataPairs;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other) = default;
        BitcoinExchange& operator=(const BitcoinExchange& other) = default;
        ~BitcoinExchange() = default;

        bool    isValidDate(const std::string& date);
        bool    isValidExchangeRate(const std::string& str, float& value);
        bool    loadDataBase(const std::string& filename);
        bool    parseFloat(const std::string& str, float& value);
        void    processInput(const std::string& filename);
};
