#include "Fixed.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the fixed-point number to 0 and prints a debug message.
 */
Fixed::Fixed() : _integer(0) { }

/**
 * @brief Destructor.
 *
 * Cleans up the Fixed instance and prints a debug message.
 */
Fixed::~Fixed() { }

/**
 * @brief Copy constructor.
 *
 * Creates a new Fixed instance as a copy of another Fixed instance.
 *
 * @param other The Fixed instance to copy.
 */
Fixed::Fixed(const Fixed& other) : _integer(other._integer){ }

/**
 * @brief Copy assignment operator.
 *
 * Assigns the value from another Fixed instance.
 *
 * @param other The Fixed instance to copy from.
 * @return Reference to this Fixed instance.
 */
Fixed& Fixed::operator = (const Fixed& other){
	if (this != &other) {
		_integer = other.getRawBits();
	}
	return (*this);
}

/**
 * @brief Constructor from integer.
 *
 * Converts an integer to fixed-point representation.
 * Values are clamped to the 23-bit range.
 *
 * @param value The integer value to convert.
 */
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

/**
 * @brief Constructor from float.
 *
 * Converts a float to fixed-point representation.
 * Values are clamped to the 23-bit range.
 *
 * @param value The float value to convert.
 */
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

/**
 * @brief Gets the raw fixed-point value.
 *
 * @return The internal integer representing the fixed-point number.
 */
int	Fixed::getRawBits(void) const{ return (_integer); }

/**
 * @brief Sets the raw fixed-point value.
 *
 * @param raw The new integer value representing the fixed-point number.
 */
void	Fixed::setRawBits(int const raw){ _integer = raw; }

/**
 * @brief Converts the fixed-point value to a floating-point number.
 *
 * @return The value as a float.
 */
float Fixed::toFloat(void) const { return (float)_integer / (1 << _fractionbits); }

/**
 * @brief Converts the fixed-point value to an integer.
 *
 * Fractional part is truncated.
 *
 * @return The value as an int.
 */
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

/**
 * @brief Overload of << operator for printing Fixed as float.
 *
 * @param out The output stream.
 * @param value The Fixed instance to print.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& out, const Fixed& value) { out << value.toFloat(); return out; }
