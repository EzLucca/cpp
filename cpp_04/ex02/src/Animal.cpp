#include "Animal.hpp"

Animal::Animal(void) : _type("default") {
	std::cout << "Animal default constructor called.\n";
}

Animal::~Animal(void) {
	std::cout << "Animal default destructor called.\n";
}

Animal::Animal(std::string type) : _type(type) {
	std::cout << "Animal type constructor called.\n";
};

Animal::Animal(const Animal &other) {
	_type = other._type;
	std::cout << "Animal copy constructor called.\n";
};

Animal &Animal::operator=(const Animal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout	<< "Animal copy assigment operator called.\n";
	return (*this);
};

std::string		Animal::getType(void) const {
	return(_type);
}

// void	Animal::makeSound(void) const {
// 	std::cout << "Animal ....\n";
// };
