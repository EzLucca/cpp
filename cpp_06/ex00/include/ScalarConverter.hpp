#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <cmath>

class ScalarConverter {
	private:

	public:
		ScalarConverter(void) = delete;
		ScalarConverter(const ScalarConverter &other) = delete;
		ScalarConverter &operator=(const ScalarConverter &other) = delete;
		~ScalarConverter(void);
		static void convert(const std::string& literal);
};

#endif // SCALARCONVERTER_HPP
