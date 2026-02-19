#include "HumanA.hpp"

/**
 * @brief Constructor.
 *
 * Initializes the human with a name and a reference to a weapon.
 * The human takes no ownership of the weapon; it must exist for
 * the lifetime of HumanA.
 *
 * @param nameA The name of the human.
 * @param weaponA Reference to the weapon the human will use.
 */
HumanA::HumanA(std::string nameA, Weapon &weaponA)
    : name(nameA), weapon(weaponA) {}

/**
 * @brief Makes the human attack with their weapon.
 *
 * Prints an attack message including the human's name and the weapon type.
 */
void HumanA::attack() {
    std::cout << name << " attacks with the "
		<< weapon.getType() << std::endl;
}

/**
 * @brief Destructor.
 *
 * Cleans up the HumanA instance.
 * The weapon is not deleted because HumanA does not own it.
 */
HumanA::~HumanA() {}
