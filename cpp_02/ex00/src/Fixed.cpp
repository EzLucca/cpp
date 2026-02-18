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
Fixed::Fixed(const Fixed& other) : _integer(other._integer) {
    std::cout << "Copy constructor called.\n";
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
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called.\n";
    if (this != &other) {
        _integer = other.getRawBits();
    }
    return *this;
}

/**
 * @brief Gets the raw fixed-point value.
 *
 * Prints a debug message and returns the internal integer representation.
 *
 * @return The internal fixed-point integer value.
 */
int	Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called.\n";
    return _integer;
}

/**
 * @brief Sets the raw fixed-point value.
 *
 * Prints a debug message and updates the internal fixed-point integer value.
 *
 * @param raw The new integer value to set.
 */
void	Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called.\n";
    _integer = raw;
}
