#include "ScalarConverter.hpp"

// int main(int argc, char **argv)
// {
//     if (argc != 2)
//         return 1;
//
//     ScalarConverter::convert(argv[1]);
// }

int main()
{
    ScalarConverter::convert("2147483647");
	std::cout << "---\n";
    ScalarConverter::convert("-2147483648");
	std::cout << "---\n";
    ScalarConverter::convert("2147483648");
	std::cout << "---\n";
    ScalarConverter::convert("2147jfksdjf483648");
	std::cout << "---\n";
    ScalarConverter::convert("2147jfksdjf483648");
	std::cout << "---\n";
    ScalarConverter::convert("214747598234758972304570274358728074507408957230975483648");
	std::cout << "---\n";
}
