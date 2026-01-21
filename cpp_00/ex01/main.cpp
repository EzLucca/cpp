#include "Phonebook.hpp"

int main (void)
{
	// Phonebook book = Phonebook();
	std::string command;
	while(1)
	{
		std::cout << "Enter a command ADD, SEARCH or EXIT: ";
		if(!std::getline(std::cin, command))
		{
			std::cout << "\nEOF detected\n";
		}
		if(command == "ADD")
		{
			std::cout << "Add if\n";
		}
		else if(command == "SEARCH")
		{
			std::cout << "search if\n";
		}
		else if(command == "EXIT")
		{
			std::cout << "exit if\n";
		}
		else
			std::cout << "Invalid command\n";
	}
	return 0;
}
