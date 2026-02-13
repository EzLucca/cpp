
#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv) {
	Harl speak;
	int	warning = 0;

	if (argc != 2) {
		std::cerr << "Wrong parameter input.\nShould be ./program <warning level>\n";
		return (1);
	}
	std::string input[] { "DEBUG", "INFO", "WARNING", "ERROR" };
	std::string level = argv[1];

	for (int i = 0; i < 4; i++) {
		if (level == input[i]) {
			warning = i + 1;	
			break ;
		}
	}
	switch (warning) {
		case 1:
			std::cout << "[ DEBUG ]\n";
			speak.complain("DEBUG");
			std::cout << "\n";
			[[fallthrough]];
		case 2:
			std::cout << "[ INFO ]\n";
			speak.complain("INFO");
			std::cout << "\n";
			[[fallthrough]];
		case 3:
			std::cout << "[ WARNING ]\n";
			speak.complain("WARNING");
			std::cout << "\n";
			[[fallthrough]];
		case 4:
			std::cout << "[ ERROR ]\n";
			speak.complain("ERROR");
			break ;
		default:
			speak.complain("");
	}
}
