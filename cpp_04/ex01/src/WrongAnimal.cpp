#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("default") {
	std::cout << "WrongAnimal default constructor called.\n";
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal default destructor called.\n";
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal type constructor called.\n";
};

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	_type = other._type;
	std::cout << "WrongAnimal copy constructor called.\n";
};

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout	<< "WrongAnimal copy assigment operator called.\n";
	return (*this);
};

std::string		WrongAnimal::getType(void) const {
	return(_type);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal ....from " << this->_type << "\n";
};
