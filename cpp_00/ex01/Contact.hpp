#pragma once

#include <iostream>

class Contact
{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkSecret;
	public:
		Contact();
		Contact(std::string name, std::string surname, std::string nick, std::string phone, std::string secret);
		const std::string& getFirstName() const;
		const std::string& getLastName() const;
		const std::string& getNickName() const;
		const std::string& getPhoneNumber() const;
		const std::string& getDarkSecret() const;
		void printInfo() const;
		~Contact();
};
