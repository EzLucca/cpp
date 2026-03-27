#include "ScalarConverter.hpp"

/**
 * @brief Destructor.
 *
 * Called when the ScalarConverter object is destroyed.
 */
ScalarConverter::~ScalarConverter(void) {}

/**
 * @brief Checks whether a string represents a single non-digit character.
 *
 * This function determines if the input string can be interpreted as a character
 * literal (excluding numeric digits).
 *
 * @param s The input string to evaluate.
 * @return true if the string represents a single non-digit character, false otherwise.
 */
static bool isChar(const std::string& s) {
	return s.length() == 1 && !isdigit(s[0]);
}

/**
 * @brief Checks whether a string is a recognized pseudo-literal.
 *
 * Pseudo-literals represent special floating-point values that cannot be expressed
 * as standard numeric literals.
 *
 * @param s The input string to evaluate.
 * @return true if the string matches a known pseudo-literal, false otherwise.
 */
static bool isPseudo(const std::string& s) {
	return ( s == "nan" || s == "nanf" ||
			s == "+inf" || s == "-inf" ||
			s == "+inff" || s == "-inff"); 
}

/**
 * @brief Converts a string literal to multiple scalar types and prints the results.
 *
 * This function takes a string representation of a value and attempts to convert it
 * into different scalar types: char, int, float, and double. It handles special
 * pseudo-literals (such as NaN and infinity) as well as single character inputs.
 *
 * @param literal The input string representing the value to convert.
 */
void ScalarConverter::convert(const std::string& literal){

	double value;

	try {
		if (isPseudo(literal))
			value = std::stod(literal);
		else if (isChar(literal))
			value = static_cast<double>(literal[0]);
		else
			value = std::stod(literal);
	}
	catch (const std::invalid_argument&) {
		std::cout << "Error: invalid literal\n";
		return;
	}
	catch (const std::out_of_range&) {
		std::cout << "Error: out of range\n";
		return;
	}

	// char
	std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "impossible\n";
	else if (!std::isprint(static_cast<unsigned char>(value)))
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
