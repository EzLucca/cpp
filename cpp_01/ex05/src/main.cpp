#include "Harl.hpp"

int	main() {
	Harl speak;

	std::cout << "Testing debug...\n";
	speak.complain("DEBUG");
	std::cout << "\nTesting info...\n";
	speak.complain("INFO");
	std::cout << "\nTesting warning...\n";
	speak.complain("WARNING");
	std::cout << "\nTesting error...\n";
	speak.complain("ERROR");
	std::cout << "\nTesting random...\n";
	speak.complain("TEST");
	speak.complain("");
	speak.complain("T");
	speak.complain("+++");
	speak.complain(" ");
}
