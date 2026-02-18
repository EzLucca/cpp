#include "WrongAnimal.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes a WrongAnimal with a default type.
 */
WrongAnimal::WrongAnimal(void) : _type("default") {
	std::cout << "WrongAnimal default constructor called.\n";
}

/**
 * @brief Destructor.
 *
 * Called when the WrongAnimal object is destroyed.
 *
 * Note: Not virtual, demonstrating improper polymorphism.
 */
WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal default destructor called.\n";
}

/**
 * @brief Constructor with type.
 *
 * @param type The type assigned to the WrongAnimal.
 */
WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "WrongAnimal type constructor called.\n";
}

/**
 * @brief Copy constructor.
 *
 * Creates a new WrongAnimal by copying another one.
 *
 * @param other The WrongAnimal object to copy from.
 */
WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	_type = other._type;
	std::cout << "WrongAnimal copy constructor called.\n";
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another WrongAnimal to this instance.
 *
 * @param other The WrongAnimal object to assign from.
 * @return Reference to the assigned WrongAnimal.
 */
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other) {
		this->_type = other._type;
	}
	std::cout << "WrongAnimal copy assigment operator called.\n";
	return (*this);
}

/**
 * @brief Get the type of the WrongAnimal.
 *
 * @return A string representing the animal type.
 */
std::string WrongAnimal::getType(void) const {
	return (_type);
}

/**
 * @brief Make the animal sound.
 *
 * Base implementation for WrongAnimal.
 * Since makeSound() is not virtual, derived classes
 * cannot override it polymorphically.
 */
void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal ....from " << this->_type << "\n";
}
