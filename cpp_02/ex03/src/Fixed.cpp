#include "Fixed.hpp"

//Constructor
Fixed::Fixed() : _integer(0) { }

//Destructor
Fixed::~Fixed() { }

//Copy constructor
Fixed::Fixed(const Fixed& other) : _integer(other._integer){ }

//Copy assignement constructor
Fixed& Fixed::operator = (const Fixed& other){
	if (this != &other) {
		_integer = other.getRawBits();
	}
	return (*this);
}

Fixed::Fixed(const int value) {
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

// Member function
int	Fixed::getRawBits(void) const{ return (_integer); }

void	Fixed::setRawBits(int const raw){ _integer = raw; }

float Fixed::toFloat(void) const { return (float)_integer / (1 << _fractionbits); }

int Fixed::toInt(void) const { return _integer >> _fractionbits; }

// Comparison operators overload
bool	Fixed::operator > (const Fixed& other) const { return (_integer > other.getRawBits()); };
bool	Fixed::operator < (const Fixed& other) const { return (_integer < other.getRawBits()); };
bool	Fixed::operator >= (const Fixed& other) const { return (_integer >= other.getRawBits()); };
bool	Fixed::operator <= (const Fixed& other) const { return (_integer <= other.getRawBits()); };
bool	Fixed::operator == (const Fixed& other) const { return (_integer == other.getRawBits()); };
bool	Fixed::operator != (const Fixed& other) const { return (_integer != other.getRawBits()); };

// Arithmetic operators overload
Fixed Fixed::operator + (const Fixed& other) const { return (Fixed(this->toFloat() + other.toFloat())); };
Fixed Fixed::operator - (const Fixed& other) const { return (Fixed(this->toFloat() - other.toFloat())); };
Fixed Fixed::operator * (const Fixed& other) const { return (Fixed(this->toFloat() * other.toFloat())); };
Fixed Fixed::operator / (const Fixed& other) const {
	if (other. getRawBits() == 0) {

		std::cerr << "Error. Division by zero.\n";
		return (Fixed());
	}
	return (Fixed(this->toFloat() * other.toFloat()));
};

// Increment/decremente operators overload
Fixed &Fixed::operator ++ (void) { _integer++; return (*this); };
Fixed &Fixed::operator -- (void) { _integer--; return (*this); };
Fixed Fixed::operator ++ (int) { Fixed value(*this); ++(*this); return (value); };
Fixed Fixed::operator -- (int) { Fixed value(*this); --(*this); return (value); };

// Static member function
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a.operator<(b) ? a : b); };
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a.operator>(b) ? a : b); };
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a.operator<(b) ? a : b); };
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a.operator>(b) ? a : b); };

std::ostream& operator<<(std::ostream& out, const Fixed& value) { out << value.toFloat(); return out; }
