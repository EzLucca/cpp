#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"

int	main () {
	{
		std::cout << "\n----- [ Test 1: Subject default constructor ] -----\n\n";
		try
		{
			Bureaucrat boss("Boss", 1);
			ShrubberyCreationForm form("shrubbery");

			boss.signForm(form);
			boss.executeForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}}

	return 0;
}
