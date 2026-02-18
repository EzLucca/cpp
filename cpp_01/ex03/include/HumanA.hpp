#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

/**
 * @brief Class representing a human equipped with a weapon.
 *
 * HumanA always has a weapon reference that must be provided at construction.
 * The HumanA can attack using the weapon.
 */
class HumanA {
	private:
		std::string name;
		Weapon &weapon;

	public:
		HumanA(std::string nameA, Weapon &weaponA);
		~HumanA();
		void attack();
};

#endif // HUMANA_HPP
