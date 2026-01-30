#include "Contact.hpp"
#include <iostream>

Contact::Contact(){};

Contact::Contact(std::string name, std::string surname, std::string nick, std::string number, std::string secret)
{
	firstName = name;
	lastName = surname;
	nickName = nick;
	phoneNumber = number;
	darkestSecret = secret;
}
const std::string& Contact::getFirstName() const { return firstName; }
const std::string& Contact::getLastName() const { return lastName; }
const std::string& Contact::getNickName() const { return nickName; }
const std::string& Contact::getPhoneNumber() const { return phoneNumber; }
const std::string& Contact::getDarkestSecret() const { return darkestSecret; }

void	Contact::printInfo() const
{
	std:: cout << "First name: " << getFirstName() << std::endl;
	std:: cout << "Last name: " << getLastName() << std::endl;
	std:: cout << "Nick name: " << getNickName() << std::endl;
	std:: cout << "Phone number: " << getPhoneNumber() << std::endl;
	std:: cout << "Dark secret: " << getDarkestSecret() << std::endl;
}
Contact::~Contact(){};
