#include "Fixed.hpp"

//Constructor
Fixed::Fixed() : _integer(0) {
	std::cout << "Default constructor called.\n";
}

//Destructor
Fixed::~Fixed() {
	std::cout << "Destructor is called.\n";
}

//Copy constructor
Fixed::Fixed(const Fixed& other) : _integer(other._integer){
	std::cout << "Copy constructor called.\n";
	// *this = other;
}

//Copy assignement constructor
Fixed& Fixed::operator = (const Fixed& other){
	std::cout << "Copy assignment operator called.\n";
	if (this != &other) {
		_integer = other.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called.\n";
	return (_integer);
}

void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called.\n";
	_integer = raw;
}
