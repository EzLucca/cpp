#include <iostream>

int main (void) {
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Memory address:\n";
	std::cout << "The memory address of string is " << &brain << std::endl;
	std::cout << "The memory address of stringPTR is " << stringPTR << std::endl;
	std::cout << "The memory address of stringREF is " << &stringREF << std::endl;

	std::cout << "Value:\n";
	std::cout << "The value of the string is " << brain << std::endl;
	std::cout << "The value of the stringPTR is " << *stringPTR << std::endl;
	std::cout << "The value of the stringREF is " << stringREF << std::endl;
}
