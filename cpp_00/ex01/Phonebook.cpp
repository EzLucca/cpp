#include "Phonebook.hpp"
#include <iomanip>
#include <thread>
#include <chrono>

// Input;
std::string getInput(std::string command)
{
	std::string userInput;
	std::cout << command ;
	std::getline(std::cin, userInput);
	return(userInput);
}

PhoneBook::PhoneBook() {
	count = 0;
	olds = 0;
};

PhoneBook::~PhoneBook() {}

// methods
void	PhoneBook::addContact(void)
{
	std::string first, last, nick, number, secret;
	std::string prompt[] = {
		"First name: ", 
		"Last name: ", 
		"nick name: ", 
		"Phone number: ", 
		"Dark secret: ", 
	};
	std::string* input[] = { &first, &last, &nick, &number, &secret };

	for(int i = 0; i < 5; ++i) {
		do {
			*input[i] = getInput(prompt[i]);
		}while(input[i]->empty());
	}
	for(int i = 0; i < 5; i++){
		std::cout << "." << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}
	std::cout << "\n";
	std::cout << "Contact was added.\n";
	Contact Contact(first, last, nick, number, secret);
	if (count < 8)
	{
		Contacts[count] = Contact;
		count++;
	}
	else
	{
		Contacts[olds] = Contact;
		olds = (olds + 1) % 8;
	}
}

std::string formatPrint(std::string text)
{
	if(text.length() > 10)
		return(text.substr(0, 9) + ".");
	return(text);
}

bool isNumber(const std::string &prompt)
{
	if (prompt.empty())
		return false;
	for (size_t i = 0; i < prompt.length(); i++)
	{
		if (!std::isdigit(prompt[i]))
			return false;
	}
	return true;
}

int	getIndexNumber(int count)
{
	std::string prompt = "Choose the index: ";
	std::string index;
	int i;
	do
	{
		index = getInput(prompt);
		if (!isNumber(index))
		{
			std::cout << "Please enter a number.\n";
			index.clear();
			continue;
		}
		i = std::stoi(index);
		if (i < 1 || i > count)
		{
			std::cout << "The number should be from 1 to " << count << ".\n";
			index.clear();
		}

	} while (index.empty());
	return (i);
}

void	PhoneBook::searchContact(void)
{
	std::cout << "\n";
	std::cout << "*******************************************\n";
	std::cout << "SUMMARY\n";
	std::cout << "*******************************************\n";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname\n"; 
	for(int i = 0; i < count; i++){
		std::cout << std::setw(10) << i + 1 << "|" 
			<< std::setw(10) << formatPrint(Contacts[i].getFirstName()) << "|"
			<< std::setw(10) << formatPrint(Contacts[i].getLastName()) << "|"
			<< std::setw(10) << formatPrint(Contacts[i].getNickName()) << std::endl;		
	}
	int index = getIndexNumber(count);
	std::cout << "*******************************************\n";
	std::cout << "\n";
	std::cout << "*******************************************\n";
	std::cout << std::setw(10) << formatPrint("First Name") << "|"
		<< std::setw(10) << formatPrint(Contacts[index - 1].getFirstName()) << "|\n";
	std::cout << std::setw(10) << formatPrint("Last Name") << "|"
		<< std::setw(10) << formatPrint(Contacts[index - 1].getLastName()) << "|\n";
	std::cout << std::setw(10) << formatPrint("Nick Name") << "|"
		<< std::setw(10) << formatPrint(Contacts[index - 1].getNickName()) << "|\n";
	std::cout << std::setw(10) << formatPrint("Phone Number") << "|"
		<< std::setw(10) << formatPrint(Contacts[index - 1].getPhoneNumber()) << "|\n";
	std::cout << std::setw(10) << formatPrint("Dark Secret") << "|"
		<< std::setw(10) << formatPrint(Contacts[index - 1].getDarkSecret()) << "|\n";	
	std::cout << "*******************************************\n";
}
