#pragma once

#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact Contacts[8];
		int	olds;
	public:
 		int count;
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
};
