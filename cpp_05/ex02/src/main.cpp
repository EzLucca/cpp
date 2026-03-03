#include "Form.hpp"
#include "Form.hpp"

int	main () {
	std::cout << "\n----- [ Test 1: Subject default constructor ] -----\n\n";
	try {
		Form f1;

		std::cout << f1 << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}

	std::cout << "\n------ [ Test 2: Parameterised constructor ] ------\n\n";
	try
	{
		Form f2("Tax Form", false, 50, 25);
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n------ [ Test 3: Copy constructor ] ------\n\n";
	try
	{
		Form original("CopyForm", false, 40, 20);
		Form copy(original);
		std::cout << "Original: \n" << original << std::endl;
		std::cout << "Copy:     \n" << copy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----- [ Test 4: Copy assignment operator ] -----\n\n";
	try
	{
		Form f3("FormA", true, 30, 10);
		Form f4("FormB", false, 60, 40);

		std::cout << "Before assignment:\n";
		std::cout << "f3: \n" << f3 << std::endl;
		std::cout << "f4: \n" << f4 << std::endl;

		f4 = f3;

		std::cout << "After assignment:\n";
		std::cout << "f3: \n" << f3 << std::endl;
		std::cout << "f4: \n" << f4 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----- [ Test 5: Testing Signed ] -----\n\n";
	try
	{
		Bureaucrat boss("Boss", 20);
		Form f6("Contract", false, 30, 10);

		f6.beSigned(boss);
		std::cout << f6 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----- [ Test 6: Testing exception ] -----\n\n";
	try
	{
		Bureaucrat intern("Intern", 100);
		Form f7("SecretForm", false, 50, 20);

		f7.beSigned(intern);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----- [ Test 7: Form already Signed ] -----\n\n";
	try
	{
		Bureaucrat chief("Chief", 10);
		Form f8("ImportantForm", false, 20, 5);

		f8.beSigned(chief);
		f8.beSigned(chief);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n----- [ Test 8: Invalid Grade ] -----\n\n";
	try
	{
		Form f9("InvalidForm", false, 0, 200);
		std::cout << f9 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
