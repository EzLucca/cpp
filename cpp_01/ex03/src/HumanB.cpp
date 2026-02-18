#include "HumanB.hpp"

/**
 * @brief Constructor.
 *
 * Initializes the human with a name. No weapon is assigned initially,
 * so the human cannot attack until a weapon is set.
 *
 * @param nameB The name of the human.
 */
HumanB::HumanB(std::string nameB) : name(nameB), weapon(nullptr) {}

/**
 * @brief Destructor.
 *
 * Cleans up the HumanB instance.
 * The weapon is not deleted because HumanB does not own it.
 */
HumanB::~HumanB() { }

/**
 * @brief Assigns a weapon to the human.
 *
 * The human does not take ownership of the weapon; the weapon must exist
 * for the lifetime of HumanB.
 *
 * @param weaponB Reference to the weapon to assign.
 */
void HumanB::setWeapon(Weapon &weaponB) {
    weapon = &weaponB;
}

/**
 * @brief Makes the human attack with their weapon.
 *
 * Prints an attack message including the human's name and the weapon type.
 * If no weapon is assigned, prints a failure message.
 */
void HumanB::attack() {
    if (weapon == nullptr) {
        std::cout << name << " fail to attack.\n";
    } else {
        std::cout << name << " attacks with the " << weapon->getType() << std::endl;
    }
}
