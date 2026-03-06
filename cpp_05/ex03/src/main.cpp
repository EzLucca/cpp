#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <cstdlib>
#include <ctime>

int	main () {
	std::srand(std::time(NULL));
	{
		std::cout << "\n----- [ Test 1: Subject default constructor ] -----\n\n";
		try
		{
			Bureaucrat boss("Boss", 44);
			ShrubberyCreationForm form1;
			RobotomyRequestForm form2;
			PresidentialPardonForm form3;

			// std::cout << form1 << std::endl;
			// std::cout << form2 << std::endl;
			// std::cout << form3 << std::endl;

			boss.signForm(form1);
			boss.executeForm(form1);
			boss.signForm(form2);
			boss.executeForm(form2);
			boss.signForm(form3);
			boss.executeForm(form3);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n----- [ Test 2: Subject parameterized constructor ] -----\n\n";
		try
		{
			Bureaucrat boss("Boss", 4);
			ShrubberyCreationForm form1("Shrubbery");
			RobotomyRequestForm form2("Robotomy");
			PresidentialPardonForm form3("Presidential");

			// std::cout << form1 << std::endl;
			// std::cout << form2 << std::endl;
			// std::cout << form3 << std::endl;

			boss.signForm(form1);
			boss.executeForm(form1);
			boss.signForm(form2);
			boss.executeForm(form2);
			boss.signForm(form3);
			boss.executeForm(form3);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n----- [ Test 3: copy constructor ] -----\n\n";
		try
		{
			Bureaucrat boss("Boss", 4);
			ShrubberyCreationForm original1("Shrubbery");
			RobotomyRequestForm original2("Robotomy");
			PresidentialPardonForm original3("Presidential");

			ShrubberyCreationForm form1(original1);
			RobotomyRequestForm form2(original2);
			PresidentialPardonForm form3(original3);

			// std::cout << form1 << std::endl;
			// std::cout << form2 << std::endl;
			// std::cout << form3 << std::endl;

			boss.signForm(form1);
			boss.executeForm(form1);
			boss.signForm(form2);
			boss.executeForm(form2);
			boss.signForm(form3);
			boss.executeForm(form3);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n----- [ Test 4: copy assignment operator ] -----\n\n";
		try
		{
			Bureaucrat boss("Boss", 4);
			ShrubberyCreationForm original1("Shrubbery");
			RobotomyRequestForm original2("Robotomy");
			PresidentialPardonForm original3("Presidential");

			ShrubberyCreationForm form1;
			RobotomyRequestForm form2;
			PresidentialPardonForm form3;

			form1 = original1;
			form2 = original2;
			form3 = original3;

			// std::cout << form1 << std::endl;
			// std::cout << form2 << std::endl;
			// std::cout << form3 << std::endl;

			boss.signForm(form1);
			boss.executeForm(form1);
			boss.signForm(form2);
			boss.executeForm(form2);
			boss.signForm(form3);
			boss.executeForm(form3);
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n----- [ Test: Intern form creation ] -----\n\n";

		try
		{
			Intern someRandomIntern;
			Bureaucrat boss("Boss", 15);

			AForm *form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
			if (form1)
			{
				boss.signForm(*form1);
				boss.executeForm(*form1);
				delete form1;
			}

			AForm *form2 = someRandomIntern.makeForm("robotomy request", "Bender");
			if (form2)
			{
				boss.signForm(*form2);
				boss.executeForm(*form2);
				delete form2;
			}

			AForm *form3 = someRandomIntern.makeForm("presidential pardon", "Alice");
			if (form3)
			{
				boss.signForm(*form3);
				boss.executeForm(*form3);
				delete form3;
			}

			AForm *form4 = someRandomIntern.makeForm("unknown form", "Target");
			if (form4)
				delete form4;
		}
		catch (std::exception &e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	return 0;
}
