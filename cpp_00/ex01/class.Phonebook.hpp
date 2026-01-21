#pragma once

#include "class.Contact.hpp"

class PhoneBook
{
	private:
		Contact Contact[8];
		int	olds;
	public:
		int count;
		PhoneBook();
		~PhoneBook();
		void	addContact();
		void	searchContact();
};
