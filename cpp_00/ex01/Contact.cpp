#include "Contact.hpp"
#include <iostream>

Contact::Contact(){};
const std::string& Contact::getFirstName() const { return firstName; }
const std::string& Contact::getLastName() const { return firstName; }
const std::string& Contact::getNickName() const { return firstName; }
const std::string& Contact::getPhoneNumber() const { return firstName; }
const std::string& Contact::getDarkSecret() const { return firstName; }

void	Contact::printInfo() const
{
	std:: cout << "First name: " << getFirstName() << std::endl;
	std:: cout << "Last name: " << getLastName() << std::endl;
	std:: cout << "Nick name: " << getNickName() << std::endl;
	std:: cout << "Phone number: " << getPhoneNumber() << std::endl;
	std:: cout << "Dark secret: " << getDarkSecret() << std::endl;
}
Contact::~Contact(){};
