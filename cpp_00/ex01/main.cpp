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
			std::cout << "\n*******************************************\n";
			std::cout << "\nEOF detected\n";
			std::cout << "Closing phonebook...\n";
			std::cout << "*******************************************\n";
			break;
		}
		if(command == "ADD")
		{
			book.addContact();
			if (std::cin.eof())
			{
				std::cout << "EOF\n";
				break;
			}
		}
		else if(command == "SEARCH")
		{
			book.searchContact();
			if (std::cin.eof())
			{
				std::cout << "EOF\n";
				break;
			}
		}
		else if(command == "EXIT")
		{
			std::cout << "Closing phonebook...\n";
			break;
		}
		else
			std::cout << "Invalid command\n";
	}
	return 0;
}
