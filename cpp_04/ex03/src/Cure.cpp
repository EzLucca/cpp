#include "Cure.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes a Cure Materia with the type "cure".
 */
Cure::Cure() : AMateria("cure") {}

/**
 * @brief Copy constructor.
 *
 * Creates a copy of another Cure Materia.
 *
 * @param other The Cure instance to copy.
 */
Cure::Cure(const Cure &other) : AMateria(other._type) {}

/**
 * @brief Copy assignment operator.
 *
 * Copies the type from another Cure instance.
 *
 * @param other The Cure instance to assign from.
 * @return Reference to the assigned object.
 */
Cure &Cure::operator=(const Cure &other) {
    if (this != &other)
        this->_type = other._type;
    return *this;
}

/**
 * @brief Destructor.
 *
 * Virtual to allow proper cleanup when deleted via base class pointer.
 */
Cure::~Cure() {}

/**
 * @brief Creates a clone of this Cure Materia.
 *
 * Allocates a new Cure instance that is a copy of this one.
 *
 * @return Pointer to the newly allocated Cure object.
 */
AMateria* Cure::clone() const {
    return new Cure(*this);
}

/**
 * @brief Uses the Cure Materia on a target character.
 *
 * Prints a message indicating that the target character
 * is healed.
 *
 * @param target The character affected by the Materia.
 */
void	Cure::use(ICharacter& target) {
	std::cout << "* heals "
		<< target.getName()
		<< "'s wounds *\n";
}

