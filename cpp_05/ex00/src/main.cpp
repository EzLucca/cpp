#include "Bureaucrat.hpp"

int	main () {
	std::cout <<
		"-----------------------------------------\n"
		"[ Test 1: Subject default constructor ]\n"
		"-----------------------------------------\n";

	Bureaucrat suit0;

	std::cout << suit0 << std::endl;

	std::cout <<
		"-----------------------------------------\n"
		"[ Test 2: Parameterised constructor ]\n"
		"-----------------------------------------\n";

	try{
		Bureaucrat Anna("Ana Maria Braga", 149);
		std::cout << Anna << std::endl;
		Anna.incrementGrade();
		std::cout << Anna << std::endl;
		Anna.decrementGrade();
		Anna.decrementGrade();
	}
	catch (std::exception & e){
		std::cerr << "Exception caught: " << e.what() << "\n";
	}

	std::cout <<
		"-----------------------------------------\n"
		"[ Test 3: Copy constructor ]\n"
		"-----------------------------------------\n";

	try{
		Bureaucrat silva("Silvio Santos", 150);
		Bureaucrat silva2(silva);
		std::cout << silva2 << std::endl;
		silva2.incrementGrade();
		std::cout << silva2 << std::endl;
		silva2.decrementGrade();
		silva2.decrementGrade();
		silva2.decrementGrade();
	}
	catch(std::exception &e){
		std::cerr << "Exception caught: " << e.what() << "\n";
	}

	std::cout <<
		"-----------------------------------------\n"
		"[ Test 4: Copy assignment operator ]\n"
		"-----------------------------------------\n";

	try{
		Bureaucrat flavio("flavio", 1);
		Bureaucrat aurelius = flavio;
		std::cout << aurelius << std::endl;
		aurelius.decrementGrade();
		std::cout << aurelius << std::endl;
		aurelius.incrementGrade();
		aurelius.incrementGrade();
		aurelius.incrementGrade();
		aurelius.incrementGrade();
	}
	catch(std::exception &e){
		std::cerr << "Exception caught: " << e.what() << "\n";
	}

	return 0;
}
