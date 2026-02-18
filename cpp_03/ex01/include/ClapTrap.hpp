#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

/**
 * @brief Class representing a ClapTrap robot.
 *
 * ClapTrap objects have a name, hit points, energy points, and attack damage.
 * They can attack, take damage, and repair themselves.
 */
class ClapTrap {
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:
		// Canonical form
		ClapTrap(void);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap(void);
		//others methods
		ClapTrap(const std::string name);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif // CLAPTRAP_HPP
