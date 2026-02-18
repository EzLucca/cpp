#include "AMateria.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes an AMateria with an empty type string.
 */
AMateria::AMateria() {}

/**
 * @brief Constructor with type.
 *
 * Initializes the AMateria with the given type.
 *
 * @param type The type of the Materia (e.g., "ice", "cure").
 */
AMateria::AMateria(std::string const& type) : _type(type) {}

/**
 * @brief Copy constructor.
 *
 * Creates a copy of another AMateria.
 *
 * @param other The AMateria instance to copy.
 */
AMateria::AMateria(const AMateria &other) : _type(other._type) {}

/**
 * @brief Copy assignment operator.
 *
 * Copies the type from another AMateria.
 *
 * @param other The AMateria instance to assign from.
 * @return Reference to the assigned object.
 */
AMateria &AMateria::operator=(const AMateria &other) {
    if (this != &other)
        _type = other._type;
    return *this;
}

/**
 * @brief Destructor.
 *
 * Virtual to ensure proper cleanup of derived Materia objects.
 */
AMateria::~AMateria() {}

/**
 * @brief Gets the type of the Materia.
 *
 * @return Constant reference to the type string.
 */
std::string const& AMateria::getType() const { return _type; }

/**
 * @brief Uses the Materia on a target.
 *
 * Default implementation does nothing. Derived classes
 * should override this method to define specific behavior.
 *
 * @param target The character affected by the Materia.
 */
void AMateria::use(ICharacter& target) { (void)target; }
