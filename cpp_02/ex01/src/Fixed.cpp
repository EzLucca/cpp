#include "Fixed.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the fixed-point number to 0 and prints a debug message.
 */
Fixed::Fixed() : _integer(0) {
	std::cout << "Default constructor called.\n";
}

/**
 * @brief Destructor.
 *
 * Cleans up the Fixed instance and prints a debug message.
 */
Fixed::~Fixed() {
	std::cout << "Destructor is called.\n";
}

/**
 * @brief Copy constructor.
 *
 * Initializes this Fixed instance as a copy of another Fixed instance.
 * Prints a debug message.
 *
 * @param other The Fixed instance to copy from.
 */
Fixed::Fixed(const Fixed& other) : _integer(other._integer){
	std::cout << "Copy constructor called.\n";
	// *this = other;
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the value from another Fixed instance.
 * Prints a debug message.
 *
 * @param other The Fixed instance to copy from.
 * @return Reference to this Fixed instance.
 */
Fixed& Fixed::operator = (const Fixed& other){
	std::cout << "Copy assignment operator called.\n";
	if (this != &other) {
		_integer = other.getRawBits();
	}
	return (*this);
}

/**
 * @brief Gets the raw fixed-point value.
 *
 * Prints a debug message and returns the internal integer representation.
 *
 * @return The internal fixed-point integer value.
 */
int	Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called.\n";
	return (_integer);
}

/**
 * @brief Sets the raw fixed-point value.
 *
 * Prints a debug message and updates the internal fixed-point integer value.
 *
 * @param raw The new integer value to set.
 */
void	Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called.\n";
	_integer = raw;
}

/**
 * @brief Constructor from integer.
 *
 * Converts an integer to fixed-point representation and prints a debug message.
 * Clamps values outside the 23-bit range.
 *
 * @param value The integer value to convert.
 */
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

/**
 * @brief Constructor from float.
 *
 * Converts a float to fixed-point representation and prints a debug message.
 * Clamps values outside the 23-bit range.
 *
 * @param value The float value to convert.
 */
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

/**
 * @brief Converts the fixed-point value to a floating-point number.
 *
 * @return The value as a float.
 */
float Fixed::toFloat(void) const {
	return (float)_integer / (1 << _fractionbits);
}

/**
 * @brief Converts the fixed-point value to an integer.
 *
 * The fractional part is truncated.
 *
 * @return The value as an int.
 */
int Fixed::toInt(void) const {
	return _integer >> _fractionbits;
}

/**
 * @brief Overload of the insertion operator.
 *
 * Prints the fixed-point number as a float.
 *
 * @param out The output stream.
 * @param value The Fixed instance to print.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& out, const Fixed& value) {
	out << value.toFloat();
	return out;
}
