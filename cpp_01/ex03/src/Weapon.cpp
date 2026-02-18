#include "Weapon.hpp"

/**
 * @brief Constructor.
 *
 * Initializes the Weapon with the given type.
 *
 * @param name The type or name of the weapon.
 */
Weapon::Weapon(std::string name) {
    type = name;
}

/**
 * @brief Sets or updates the type of the weapon.
 *
 * Changes the Weapon's type to the given value.
 *
 * @param typeWeapon The new type or name of the weapon.
 */
void Weapon::setType(std::string typeWeapon) {
    type = typeWeapon;
}

/**
 * @brief Gets the type of the weapon.
 *
 * Returns a constant reference to the Weapon's type.
 *
 * @return Constant reference to the type of the weapon.
 */
const std::string &Weapon::getType(void) const {
    return type;
}

/**
 * @brief Destructor.
 *
 * Cleans up the Weapon instance.
 */
Weapon::~Weapon() {}
