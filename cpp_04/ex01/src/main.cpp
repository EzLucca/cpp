#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Subject default test ]" << std::endl
				<< "-----------------------------------------" << std::endl;
	
	const Animal*	meta = nullptr;
	const Animal*	j = nullptr;
	const Animal*	i = nullptr;
	
	try {
		meta = new Animal();
		j = new Dog();
		i = new Cat();

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << j->getType() << " " << std::endl;
		j->makeSound();
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << meta->getType() << " " << std::endl;
		meta->makeSound();
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;

		delete i;
		delete j;
		delete meta;
		return (1);
	}
	
	delete i;
	delete j;
	delete meta;

	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ Test: Subject WrongAnimal test ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	const WrongAnimal*	a = nullptr;
	const WrongAnimal*	cat = nullptr;

	try {
		a = new WrongAnimal();
		cat = new WrongCat();

		std::cout << "-----------------------------------------" << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		std::cout << "-----------------------------------------" << std::endl;
		std::cout << a->getType() << " " << std::endl;
		a->makeSound();
		std::cout << "-----------------------------------------" << std::endl;
	}
	catch (const std::bad_alloc& e) {
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
		
		delete cat;
		delete a;
	}

	delete cat;
	delete a;
	
	std::cout	<< "-----------------------------------------" << std::endl
				<< "[ All tests done! ]" << std::endl
				<< "-----------------------------------------" << std::endl;

	return (0);
}
