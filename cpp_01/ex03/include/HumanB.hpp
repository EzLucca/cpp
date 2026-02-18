#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

/**
 * @brief Class representing a human who can hold a weapon optionally.
 *
 * HumanB can exist without a weapon initially and can be assigned a weapon later
 * using `setWeapon()`. The attack behavior depends on whether a weapon is assigned.
 */
class HumanB {
	private:
		std::string name;
		Weapon *weapon;

	public:
		HumanB(std::string nameB);
		~HumanB();
		void attack();
		void	setWeapon(Weapon &weaponB);
};

#endif // HUMANB_HPP
