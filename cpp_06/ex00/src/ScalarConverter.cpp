#include "ScalarConverter.hpp"

/**
 * @brief Destructor.
 *
 * Called when the ScalarConverter object is destroyed.
 */
ScalarConverter::~ScalarConverter(void) {}

static bool isChar(const std::string& s) {
	return s.length() == 1 && !isdigit(s[0]);
}

static bool isPseudo(const std::string& s) {
	return ( s == "nan" || s == "nanf" ||
			s == "+inf" || s == "-inf" ||
			s == "+inff" || s == "-inff"); 
}

void ScalarConverter::convert(const std::string& literal){

	double value;

	if (isPseudo(literal))
		value = std::strtod(literal.c_str(), NULL);
	else if(isChar(literal))
		value = static_cast<double>(literal[0]);
	else
		value = std::strtod(literal.c_str(), NULL);

	// char
	std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "impossible\n";
	else if (!isprint(static_cast<char>(value)))
		std::cout << "Non displayable\n";
	else
		std::cout << "'" << static_cast<char>(value) << "'\n";

	// int
	std::cout << "int: ";
	if (std::isnan(value) ||
			value > std::numeric_limits<int>::max() ||
			value < std::numeric_limits<int>::min())
		std::cout << "impossible\n";
	else
		std::cout << static_cast<int>(value) << "\n";

	// float
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(1)
		<< static_cast<float>(value) << "f\n";

	// double
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(1)
		<< static_cast<double>(value) << "\n";
}
