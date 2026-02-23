#include "Cat.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes a Cat object and sets its type to "Cat".
 */
Cat::Cat(void) : Animal() {
	_type = "Cat";
	std::cout << "Cat default constructor called.\n";
}

/**
 * @brief Destructor.
 *
 * Called when the Cat object is destroyed.
 */
Cat::~Cat(void) {
	std::cout << "Cat default destructor called.\n";
}

/**
 * @brief Constructor with type.
 *
 * Calls the Animal constructor and sets the type to "Cat".
 *
 * @param type Unused parameter kept for interface consistency.
 */
Cat::Cat(std::string type) : Animal(type) {
	_type = "Cat";
	std::cout << "Cat type constructor called.\n";
}

/**
 * @brief Copy constructor.
 *
 * Creates a new Cat by copying another one.
 *
 * @param other The Cat object to copy from.
 */
Cat::Cat(const Cat &other) : Animal(other) {
	_type = other._type;
	std::cout << "Cat copy constructor called.\n";
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the values of another Cat to this instance.
 *
 * @param other The Cat object to assign from.
 * @return Reference to the assigned Cat.
 */
Cat &Cat::operator=(const Cat &other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	std::cout << "Cat copy assigment operator called.\n";
	return (*this);
}

/**
 * @brief Make the cat sound.
 *
 * Overrides Animal::makeSound() with a cat-specific sound.
 */
void	Cat::makeSound(void) const {
	std::cout << "Cat meow meow\n";
}
