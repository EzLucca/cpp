#include "easyfind.hpp"

void	testvector() {
	std::cout << "----- Testing std::vector -----\n";

	std::vector<int> vec = {1, 2, 5, 60, 4};
	std::vector<int> tests = {5, 25, -5, 0, 4};

	for (int val : tests){
		try {
			std::cout << "Found: "<< *easyfind(vec, val) << "\n";
		}
		catch (const std::exception &e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}
}

void	testlist() {
	std::cout << "----- Testing std::list -----\n";

	std::list<int> vec = {1, 2, 5, 60, 4};
	std::list<int> tests = {5, 25, -5, 0, 4};

	for (int val : tests){
		try {
			std::cout << "Found: "<< *easyfind(vec, val) << "\n";
		}
		catch (const std::exception &e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}
}

void	testconst() {
	std::cout << "----- Testing std::vector -----\n";

	const std::vector<int> vec = {1, 2, 5, 60, 4};
	std::vector<int> tests = {5, 25, -5, 0, 4};

	for (int val : tests){
		try {
			std::cout << "Found: "<< *easyfind(vec, val) << "\n";
		}
		catch (const std::exception &e) {
			std::cout << "Error: " << e.what() << "\n";
		}
	}
}

int main ()
{
	testvector();
	testlist();
	testconst();
	return 0;
}
