#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
		std::string _name;

	public:
		// Canonical methods Constructor, copy, assignment and destructor
		DiamondTrap(void);
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap(void);
		// Other methods
		DiamondTrap(const std::string name);
		using ScavTrap::attack;
		void	whoAmI(void);
		// void	howManyPoints(void);
};

#endif // DIAMONDTRAP_HPP
