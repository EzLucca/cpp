#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called.\n";
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat default destructor called.\n";
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	this->_type = "WrongCat";
	std::cout << "WrongCat type constructor called.\n";
};

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	_type = other._type;
	std::cout << "WrongCat copy constructor called.\n";
};

WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout	<< "WrongCat copy assigment operator called.\n";
	return (*this);
};

void	WrongCat::makeSound(void) const {
	std::cout << "WrongCat meow meow\n";
};
