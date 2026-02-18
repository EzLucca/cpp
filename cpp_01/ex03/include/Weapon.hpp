#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

/**
 * @brief Class representing a weapon.
 *
 * A Weapon has a type (name) and can be modified after creation.
 * Humans can hold or reference a Weapon to perform attacks.
 */
class Weapon {
	private:
		std::string type;

	public:
		Weapon(std::string name);
		~Weapon();
		const std::string &getType() const;
		void	setType(std::string type);
};

#endif // WEAPON_HPP
