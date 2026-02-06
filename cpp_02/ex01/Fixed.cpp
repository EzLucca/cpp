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

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called.\n";
	if (value > MAX23BITS) {
		std::cout << "Number bigger than 23 bits. The max value will be saved.\n";
		_integer = MAX23BITS << _fractionbits;
	}
	else if (value < MIN23BITS){
		std::cout << "Number smaller than 23 bits. The min value will be saved.\n";
		_integer = MIN23BITS * (1 << _fractionbits);
	}
	else {
		_integer = value << _fractionbits;
	}
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called.\n";
	if (value > MAX23BITS) {
		_integer = roundf(MAX23BITS * (1 << _fractionbits));
	}
	else if (value < MIN23BITS){
		_integer = roundf(MIN23BITS * (1 << _fractionbits));
	}
	else {
	_integer = roundf(value * (1 <<  _fractionbits));
	}
}

float Fixed::toFloat(void) const {
	return (float)_integer / (1 << _fractionbits);
}

int Fixed::toInt(void) const {
	return _integer >> _fractionbits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return out;
}
