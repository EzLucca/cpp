#include "Character.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes a Character with an empty name and clears the inventory.
 */
Character::Character() {}

/**
 * @brief Constructor with name.
 *
 * Initializes a Character with the given name and sets all inventory slots to empty.
 *
 * @param name The name of the character.
 */
Character::Character(std::string const& name) : _name(name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
}

/**
 * @brief Copy constructor.
 *
 * Performs a deep copy of another Character, including cloning
 * any Materia in the inventory.
 *
 * @param other The Character instance to copy.
 */
Character::Character(const Character &other) : _name(other._name) {
    for (int i = 0; i < 4; i++)
        _inventory[i] = 0;
    *this = other;
}

/**
 * @brief Copy assignment operator.
 *
 * Performs a deep copy of another Character. Deletes any existing
 * Materia in the inventory before cloning from the source.
 *
 * @param other The Character instance to assign from.
 * @return Reference to the assigned object.
 */
Character &Character::operator=(const Character &other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0;i < 4; i++) {
			delete _inventory[i];
			_inventory[i] = other._inventory[i] ? other._inventory[i]->clone() : nullptr;
		}
	}
	return(*this);
}

/**
 * @brief Destructor.
 *
 * Deletes all Materia stored in the inventory to avoid memory leaks.
 */
Character::~Character() {
    for (int i = 0; i < 4; i++)
        delete _inventory[i];
}

/**
 * @brief Gets the name of the character.
 *
 * @return Constant reference to the character's name.
 */
std::string const& Character::getName() const {
    return _name;
}

/**
 * @brief Equips a Materia into the first available inventory slot.
 *
 * Ownership of the Materia is transferred to the Character.
 * If all slots are full or the pointer is NULL, nothing happens.
 *
 * @param m Pointer to the AMateria to equip.
 */
void	Character::equip(AMateria* m) {
    if (!m)
        return;
    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
}

/**
 * @brief Unequips a Materia from the inventory.
 *
 * Does not delete the Materia. Caller is responsible for memory.
 *
 * @param idx Index of the inventory slot to unequip (0-3).
 */
void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	_inventory[idx] = 0;
}

/**
 * @brief Uses the Materia in the given inventory slot on a target character.
 *
 * If the slot is empty or index is invalid, does nothing.
 *
 * @param idx Index of the Materia to use (0-3).
 * @param target The character to be affected by the Materia.
 */
void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3 || !_inventory[idx])
		return ;
	_inventory[idx]->use(target);
}
