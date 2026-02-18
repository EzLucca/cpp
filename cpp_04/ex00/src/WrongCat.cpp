#include "WrongCat.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes a WrongCat object and sets its type to "WrongCat".
 */
WrongCat::WrongCat(void) : WrongAnimal() {
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called.\n";
}

/**
 * @brief Destructor.
 *
 * Called when the WrongCat object is destroyed.
 *
 * Note: Does not override a virtual destructor.
 */
WrongCat::~WrongCat(void) {
	std::cout << "WrongCat default destructor called.\n";
}

/**
 * @brief Constructor with type.
 *
 * Calls the WrongAnimal constructor and sets the type to "WrongCat".
 *
 * @param type Unused parameter kept for interface consistency.
 */
WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	this->_type = "WrongCat";
	std::cout << "WrongCat type constructor called.\n";
}

/**
 * @brief Copy constructor.
 *
 * Creates a new WrongCat by copying another one.
 *
 * @param other The WrongCat object to copy from.
 */
WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
	_type = other._type;
	std::cout << "WrongCat copy constructor called.\n";
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another WrongCat to this instance.
 *
 * @param other The WrongCat object to assign from.
 * @return Reference to the assigned WrongCat.
 */
WrongCat &WrongCat::operator=(const WrongCat &other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	std::cout << "WrongCat copy assigment operator called.\n";
	return (*this);
}

/**
 * @brief Make the cat sound.
 *
 * This function hides WrongAnimal::makeSound() instead of
 * overriding it polymorphically. Polymorphism does not work
 * due to WrongAnimal::makeSound() not being virtual.
 */
void WrongCat::makeSound(void) const {
	std::cout << "WrongCat meow meow\n";
}
