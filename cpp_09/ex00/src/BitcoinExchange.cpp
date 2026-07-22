#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

static std::string trim(const std::string& s)
{
    size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start])))
        ++start;

    size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1])))
        --end;

    return s.substr(start, end - start);
}

bool BitcoinExchange::isValidDate(const std::string& date) 
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    try
    {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8, 2));

        std::chrono::year_month_day ymd{
            std::chrono::year{year},
                std::chrono::month{static_cast<unsigned>(month)},
                std::chrono::day{static_cast<unsigned>(day)}
        };

        return ymd.ok();
    }
    catch (...)
    {
        return false;
    }
}

bool BitcoinExchange::parseFloat(const std::string& str, float& value)
{
    if (str.empty())
        return false;

    char* end = NULL;
    value = std::strtof(str.c_str(), &end);

    // No characters were converted
    if (end == str.c_str())
        return false;

    // Extra characters after the number
    if (*end != '\0')
        return false;

    // Reject NaN and infinity
    if (!std::isfinite(value))
        return false;

    return true;
}

bool BitcoinExchange::isValidExchangeRate(const std::string& str, float& value)
{
    if (!parseFloat(str, value))
        return false;

    return value >= 0;
}

bool BitcoinExchange::loadDataBase(const std::string& filename)
{
    _dataPairs.clear();
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
        float value = 0.0f;
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
    if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".txt")
    {
        std::cerr << "Error: Filename should be input.txt" << std::endl;
    }
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

        float value = 0.0f;

        if (!parseFloat(valueStr, value))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }

        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
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
