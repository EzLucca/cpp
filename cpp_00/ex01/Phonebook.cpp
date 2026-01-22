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
		*input[i] = getInput(prompt[i]);
	}
	for(int i = 0; i < 5; i++){
		std::cout << ".." << std::flush;
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

std::string center(const std::string& text, int width)
{
	if ((int)text.length() >= width)
		return text.substr(0, width);

	int padding = width - text.length();
	int left = padding / 2;
	int right = padding - left;

	return std::string(left, ' ') + text + std::string(right, ' ');
}

void	PhoneBook::searchContact(void)
{
	// std::cout << "                   SUMMARY                   \n";
	std::cout << "\n\n";
	std::cout << "SUMMARY\n";
	std::cout << "********** ********** ********** **********\n";
	// std::cout << std::setw(10) << "Index" << "|";
	// std::cout << std::setw(10) << "First Name" << "|";
	// std::cout << std::setw(10) << "Last Name" << "|";
	// std::cout << std::setw(10) << "Nickname" << std::endl; 
	std::cout << center("Index", 10) << "|";
	std::cout << center("First Name", 10) << "|";
	std::cout << center("Last Name", 10) << "|";
	std::cout << center("Nickname", 10) << std::endl; 
	for(int i = 0; i < count; i++){
		std::cout << std::setw(10) << i + 1 << "|" 
		<< std::setw(10) << formatPrint(Contacts[i].getFirstName()) << "|"
		<< std::setw(10) << formatPrint(Contacts[i].getLastName()) << "|"
		<< std::setw(10) << formatPrint(Contacts[i].getNickName()) << std::endl;		
	}
}
