#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
    private:
        std::string _dataBase;
        std::map<std::string, float> _dataPairs;

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string& file);
        BitcoinExchange(const BitcoinExchange& other) = default;
        BitcoinExchange& operator=(const BitcoinExchange& other) = default;
        ~BitcoinExchange() = default;
        bool    loadDataBase(const std::string& filename);
        bool    isValidDate(const std::string& date);
        bool    isValidValue(const std::string& valueStr, float &value);
        bool    loadDatabase(const std::string& filename);
        void    processInput(const std::string& filename);
};
