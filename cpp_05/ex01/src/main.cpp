#include "Bureaucrat.hpp"

int	main () {
	std::cout <<
		"-----------------------------------------\n"
		"[ Test 1: Subject default constructor ]\n"
		"-----------------------------------------\n";

	Bureaucrat suit0;

	std::cout << "name: " << suit0.getName()
		<< "\ngrade: " << suit0.getGrade() << "\n";

	std::cout <<
		"-----------------------------------------\n"
		"[ Test 2: Parameterised constructor ]\n"
		"-----------------------------------------\n";

	try{
		Bureaucrat Anna("Ana Maria Braga", 149);
		std::cout << "name: " << Anna.getName()
			<< "\ngrade: " << Anna.getGrade() << "\n";
		Anna.incrementGrade();
		std::cout << "name: " << Anna.getName()
			<< "\ngrade: " << Anna.getGrade() << "\n";
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
		std::cout << "name: " << silva2.getName()
			<< "\ngrade: " << silva2.getGrade() << "\n";
		silva2.incrementGrade();
		std::cout << "name: " << silva2.getName()
			<< "\ngrade: " << silva2.getGrade() << "\n";
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
		std::cout << "name: " << aurelius.getName()
			<< "\ngrade: " << aurelius.getGrade() << "\n";
		aurelius.decrementGrade();
		std::cout << "name: " << aurelius.getName()
			<< "\ngrade: " << aurelius.getGrade() << "\n";
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
