#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& file) : _dataBase(file) {}

bool BitcoinExchange::loadDataBase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return false;

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, value;

        if (std::getline(ss, date, ',') && std::getline(ss, value)) {
            _dataPairs[date] = std::atof(value.c_str());
        }
    }
    return true;
}


BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string& date) {
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

bool BitcoinExchange::isValidValue(const std::string& valueStr, float &value) {
    char* end;
    value = std::strtof(valueStr.c_str(), &end);
    if (*end != '\0')
        return false;
    if (value < 0)
        return false;
    if (value > 1000)
        return false;
    return true;
}

bool BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        return false;

    std::string line;
    std::getline(file, line); // skip header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, value;

        if (std::getline(ss, date, ',') && std::getline(ss, value)) {
            _dataPairs[date] = std::atof(value.c_str());
        }
    }
    return true;
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // header

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date, valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // trim spaces
        if (valueStr.size() > 0 && valueStr[0] == ' ')
            valueStr.erase(0, 1);

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valueStr, value)) {
            if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (value > 1000)
                std::cerr << "Error: too large a number." << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::map<std::string, float>::iterator it = _dataPairs.lower_bound(date);

        if (it == _dataPairs.end() || it->first != date) {
            if (it == _dataPairs.begin()) {
                std::cerr << "Error: no earlier date available." << std::endl;
                continue;
            }
            --it;
        }

        float result = it->second * value;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}
