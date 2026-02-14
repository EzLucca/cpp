#include "Dog.hpp"

Dog::Dog(void) : Animal() {
	this->_type = "Dog";
	this->_dogBrain = new Brain();
	std::cout << "Dog default constructor called.\n";
}

Dog::~Dog(void) {
	delete this->_dogBrain;
	std::cout << "Dog default destructor called.\n";
}

Dog::Dog(std::string type) : Animal(type) {
	this->_type = "Dog";
	std::cout << "Dog type constructor called.\n";
};

Dog::Dog(const Dog &other) : Animal(other) {
	_type = other._type;
	this->_dogBrain = new Brain(*other._dogBrain);
	std::cout << "Dog copy constructor called.\n";
};

Dog &Dog::operator=(const Dog &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	this->_dogBrain = new Brain(*other._dogBrain);
	std::cout	<< "Dog copy assigment operator called.\n";
	return (*this);
};

void	Dog::makeSound(void) const {
	std::cout << "Dog hoooof hooooooff\n";
};
