#include "Ice.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes an Ice Materia with the type "ice".
 */
Ice::Ice() : AMateria("ice") {}

/**
 * @brief Copy constructor.
 *
 * Creates a copy of another Ice Materia.
 *
 * @param other The Ice instance to copy.
 */
Ice::Ice(const Ice &other) : AMateria(other._type) {}

/**
 * @brief Copy assignment operator.
 *
 * Copies the type from another Ice instance.
 *
 * @param other The Ice instance to assign from.
 * @return Reference to the assigned object.
 */
Ice &Ice::operator=(const Ice &other) {
    if (this != &other)
        _type = other._type;
    return *this;
}

/**
 * @brief Destructor.
 *
 * Virtual to allow proper cleanup when deleted via base class pointer.
 */
Ice::~Ice() {}

/**
 * @brief Creates a clone of this Ice Materia.
 *
 * Allocates a new Ice instance that is a copy of this one.
 *
 * @return Pointer to the newly allocated Ice object.
 */
AMateria* Ice::clone() const {
    return new Ice(*this);
}

/**
 * @brief Uses the Ice Materia on a target character.
 *
 * Prints a message indicating that an ice bolt is shot at the target.
 *
 * @param target The character affected by the Materia.
 */
void	Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "
		<< target.getName()
		<< " *\n";
}

