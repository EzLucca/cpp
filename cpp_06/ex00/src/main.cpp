#include "ScalarConverter.hpp"

// int main(int argc, char **argv)
// {
//     if (argc != 2)
//         return 1;
//
//     ScalarConverter::convert(argv[1]);
// }

#define COLOR "\033[0;35m"
#define RESET "\033[0;0m"

#if 1
static void	testInvalid();
static void	testChar();
static void testInteger();
static void	testFloat();
static void	testDouble();

int	main(void) {

	testInvalid();
	testChar();
	testInteger();
	testFloat();
	testDouble();

	return (0);
}

static void	testInvalid() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Invalid string representation ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '❤' ]" << RESET << std::endl;
	ScalarConverter::convert("❤");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'abc' ]" << RESET << std::endl;
	ScalarConverter::convert("abc");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '\\t' ]" << RESET << std::endl;
	ScalarConverter::convert("'\t'");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '' '' ]" << RESET << std::endl;
	ScalarConverter::convert("' '");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '😀' ]" << RESET << std::endl;
	ScalarConverter::convert("😀");
}

static void	testChar() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: string representation for Char ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'a' ]" << RESET << std::endl;
	ScalarConverter::convert("a");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '\t' ]" << RESET << std::endl;
	ScalarConverter::convert("\t");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: ' ' ]" << RESET << std::endl;
	ScalarConverter::convert(" ");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'Z' ]" << RESET << std::endl;
	ScalarConverter::convert("Z");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '*' ]" << RESET << std::endl;
	ScalarConverter::convert("*");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '+' ]" << RESET << std::endl;
	ScalarConverter::convert("+");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '/' ]" << RESET << std::endl;
	ScalarConverter::convert("/");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '@' ]" << RESET << std::endl;
	ScalarConverter::convert("@");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '?' ]" << RESET << std::endl;
	ScalarConverter::convert("?");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '0': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("0");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '9': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("0");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '木': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("木");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'ã': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("ã");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '€': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("€");
}

static void testInteger() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: string representation for Integer ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '1' ]" << RESET << std::endl;
	ScalarConverter::convert("1");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-2' ]" << RESET << std::endl;
	ScalarConverter::convert("-2");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '2222' ]" << RESET << std::endl;
	ScalarConverter::convert("2222");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '+42' ]" << RESET << std::endl;
	ScalarConverter::convert("+42");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-42' ]" << RESET << std::endl;
	ScalarConverter::convert("-42");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'INT_MAX' ]" << RESET << std::endl;
	int maxInt = std::numeric_limits<int>::max();
	std::cout << "INT_MAX = "<< maxInt << std::endl;
	std::string intStrMax = std::to_string(maxInt);
	ScalarConverter::convert(intStrMax);
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'INT_MIN' ]" << RESET << std::endl;
	int minInt = std::numeric_limits<int>::min();
	std::cout << "INT_MIN = "<< minInt << std::endl;
	std::string intStrMin = std::to_string(minInt);
	ScalarConverter::convert(intStrMin);
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: Overflow value ]" << RESET << std::endl;
	std::string intOverflow = "2147483648";
	std::cout << "Overflow value for int = " << intOverflow << std::endl;
	ScalarConverter::convert(intOverflow);
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: Underflow value ]" << RESET << std::endl;
	std::string intUnderflow = "-2147483649";
	std::cout << "Underflow value for int = "<< intUnderflow << std::endl;
	ScalarConverter::convert(intUnderflow);
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '++1234': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("++1234");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-1234abc': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("-1234abc");
	std::cout	<< COLOR <<  "[ Input: '+1234a': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("+1234a");
}
static void	testFloat() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: string representation for Float ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '0.0f' ]" << RESET << std::endl;
	ScalarConverter::convert("0.0f");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-0.5f' ]" << RESET << std::endl;
	ScalarConverter::convert("-0.5f");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '42.0f' ]" << RESET << std::endl;
	ScalarConverter::convert("42.0f");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '1234.5' ]" << RESET << std::endl;
	ScalarConverter::convert("1234.5");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '1234.5f' ]" << RESET << std::endl;
	ScalarConverter::convert("1234.5f");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-42.42' ]" << RESET << std::endl;
	ScalarConverter::convert("-42.42");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-inff' ]" << RESET << std::endl;
	ScalarConverter::convert("-inff");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '+inff' ]" << RESET << std::endl;
	ScalarConverter::convert("+inff");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'nanf' ]" << RESET << std::endl;
	ScalarConverter::convert("nanf");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'FLT_MAX' ]" << RESET << std::endl;
	float maxFloat = std::numeric_limits<float>::max();
	std::cout << "FLT_MAX = "<< maxFloat << std::endl;
	std::string floatStrMax = std::to_string(maxFloat);
	ScalarConverter::convert(floatStrMax);
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'FLT_MIN' ]" << RESET << std::endl;
	float minFloat = std::numeric_limits<float>::lowest(); //min();
	std::cout << "FLT_MIN = "<< minFloat << std::endl;
	std::string floatStrMin = std::to_string(minFloat);
	ScalarConverter::convert(floatStrMin);
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: Overflow value ]" << RESET << std::endl;
	std::string floatOverflow = "1340282346638528859811704183484516925440.0";
	std::cout << "Overflow value for float = "<< floatOverflow << std::endl;
	ScalarConverter::convert(floatOverflow);
	std::cout	<< "-----------------------------------------" << std::endl;
	// Underflow happens when a number is too small in magnitude (but non-zero). Depending on the system,
	// these values might either: Be treated as zero (i.e., float cannot represent them) or throw an error (in rare cases).
	std::cout	<< COLOR <<  "[ Input: Underflow value ]" << RESET << std::endl;
	std::string floatUnderflow = "-1.0e-50f";
	std::cout << "Underflow value for float = "<< floatUnderflow << std::endl;
	ScalarConverter::convert(floatUnderflow);
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '1.2.3f': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("1.2.3f");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '100.0ff': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("100.0ff");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '42.f' ]" << RESET << std::endl;
	ScalarConverter::convert("42.f");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '.42f' ]" << RESET << std::endl;
	ScalarConverter::convert(".42f");
}

static void	testDouble() {
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: string representation for Double ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '0.0' ]" << RESET << std::endl;
	ScalarConverter::convert("0.0");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '9.9' ]" << RESET << std::endl;
	ScalarConverter::convert("9.9");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-0.5' ]" << RESET << std::endl;
	ScalarConverter::convert("-0.5");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '+42.0' ]" << RESET << std::endl;
	ScalarConverter::convert("+42.0");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '1234.5' ]" << RESET << std::endl;
	ScalarConverter::convert("1234.5");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '42424242.42' ]" << RESET << std::endl;
	ScalarConverter::convert("42424242.42");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-42.42' ]" << RESET << std::endl;
	ScalarConverter::convert("-42.42");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '-inf' ]" << RESET << std::endl;
	ScalarConverter::convert("-inf");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '+inf' ]" << RESET << std::endl;
	ScalarConverter::convert("+inf");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'nanf' ]" << RESET << std::endl;
	ScalarConverter::convert("nan");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'DBL_MAX' ]" << RESET << std::endl;
	double maxDouble = std::numeric_limits<double>::max();
	std::cout << "DBL_MAX = "<< maxDouble << std::endl;
	std::string doubleStrMax = std::to_string(maxDouble);
	ScalarConverter::convert(doubleStrMax);
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: 'DBL_MIN' ]" << RESET << std::endl;
	double minDouble = std::numeric_limits<double>::lowest(); ///min();
	std::cout << "DBL_MIN = "<< minDouble << std::endl;
	std::string doubleStrMin = std::to_string(minDouble);
	ScalarConverter::convert(doubleStrMin);
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: Overflow value ]" << RESET << std::endl;
	double doubleOverflow = std::numeric_limits<double>::max() * 2.0;
	std::cout << "Overflow value for double = "<< doubleOverflow << std::endl;
	std::string doubleStrOverflow = std::to_string(doubleOverflow);
	ScalarConverter::convert(doubleStrOverflow);
	std::cout	<< "-----------------------------------------" << std::endl;
	// Underflow happens when a number is too small in magnitude (but non-zero): 1e-320 is below the minimum normalized positive double
	// Since the number is extremely close to 0, std::stod might fail or return a denormalized number, which then causes issues when casting 
	std::cout	<< COLOR <<  "[ Input: Underflow value ]" << RESET << std::endl;
	std::string doubleUnderflow = "1e-320";
	std::cout << "Underflow value for double = "<< doubleUnderflow << std::endl;
	ScalarConverter::convert(doubleUnderflow);
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '1.2.3': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("1.2.3");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '1..23': Invalid conversion type ]" << RESET << std::endl;
	ScalarConverter::convert("1..23");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '42.' ]" << RESET << std::endl;
	ScalarConverter::convert("42.");
	std::cout	<< "-----------------------------------------" << std::endl;
	std::cout	<< COLOR <<  "[ Input: '.42' ]" << RESET << std::endl;
	ScalarConverter::convert(".42");
	std::cout	<< "-----------------------------------------" << std::endl;
}

#endif
