#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& file) : _dataBase(file) {}

BitcoinExchange::BitcoinExchange() {}

static std::string trim(const std::string& s)
{
    size_t start = 0;
    while (start < s.size() && std::isspace(s[start]))
        ++start;

    size_t end = s.size();
    while (end > start && std::isspace(s[end - 1]))
        --end;

    return s.substr(start, end - start);
}

bool BitcoinExchange::isValidDate(const std::string& date) 
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    int y = std::atoi(date.substr(0,4).c_str());
    int m = std::atoi(date.substr(5,2).c_str());
    int d = std::atoi(date.substr(8,2).c_str());

    if (m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    if (y < 0)
        return false;
    return true;
}

bool BitcoinExchange::parseFloat(const std::string& str, float& value)
{
    char* end;

    value = std::strtof(str.c_str(), &end);

    return (*end == '\0');
}

bool BitcoinExchange::isValidExchangeRate(const std::string& str, float& value)
{
    if (!parseFloat(str, value))
        return false;

    return value >= 0;
}

bool BitcoinExchange::isValidInputValue(const std::string& str, float& value)
{
    if (!parseFloat(str, value))
        return false;

    if (value < 0)
        return false;

    if (value > 1000)
        return false;

    return true;
}

bool BitcoinExchange::loadDataBase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return false;

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad database line => " << line << std::endl;
            continue;
        }
        if (!isValidDate(date))
        {
            std::cerr << "Error: invalid date => " << date << std::endl;
            continue;
        }
        float value;
        if (!isValidExchangeRate(valueStr, value))
        {
            std::cerr << "Error: invalid value => " << valueStr << std::endl;
            continue;
        }
        _dataPairs[date] = value;
        // std::cout << date << " => " << value  << std::endl;
    }
    return true;
}

void BitcoinExchange::processInput(const std::string& filename) 
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // trim spaces
        date = trim(date);
        valueStr = trim(valueStr);

        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value;
        if (!isValidInputValue(valueStr, value))
        {
            if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (value > 1000)
                std::cerr << "Error: too large a number." << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _dataPairs.lower_bound(date);

        if (it == _dataPairs.end() || it->first != date)
        {
            if (it == _dataPairs.begin())
            {
                std::cerr << "Error: no earlier date available." << std::endl;
                continue;
            }
            --it;
        }

        float result = it->second * value;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}
