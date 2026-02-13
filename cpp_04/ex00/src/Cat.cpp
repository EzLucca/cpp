#include "Cat.hpp"

Cat::Cat(void) : Animal() {
	this->_type = "Cat";
	std::cout << "Cat default constructor called.\n";
}

Cat::~Cat(void) {
	std::cout << "Cat default destructor called.\n";
}

Cat::Cat(std::string type) : Animal(type) {
	this->_type = "Cat";
	std::cout << "Cat type constructor called.\n";
};

Cat::Cat(const Cat &other) : Animal(other) {
	_type = other._type;
	std::cout << "Cat copy constructor called.\n";
};

Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout	<< "Cat copy assigment operator called.\n";
	return (*this);
};

void	Cat::makeSound(void) const {
	std::cout << "Cat meow meow\n";
};
