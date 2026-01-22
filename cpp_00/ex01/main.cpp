#include "Phonebook.hpp"

int main (void)
{
	PhoneBook book = PhoneBook();
	std::string command;
	while(1)
	{
		std::cout << "Enter a command ADD, SEARCH or EXIT: ";
		if(!std::getline(std::cin, command))
		{
			std::cout << "\nEOF detected\n";
break;
		}
		if(command == "ADD" || command == "add")
		{
			book.addContact();
			if (std::cin.eof())
			{
				std::cout << "EOF\n";
				break;
			}
		}
		else if(command == "SEARCH" || command == "search")
		{
			book.searchContact();
			if (std::cin.eof())
			{
				std::cout << "EOF\n";
				break;
			}
		}
		else if(command == "EXIT" || command == "exit")
		{
			std::cout << "Closing phonebook...\n";
			break;
		}
		else
			std::cout << "Invalid command\n";
	}
	return 0;
}
