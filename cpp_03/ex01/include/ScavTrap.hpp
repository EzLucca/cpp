#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/**
 * @brief Class representing a ScavTrap robot.
 *
 * Inherits from ClapTrap. ScavTraps have enhanced behavior such as
 * entering gate-keeping mode.
 */
class ScavTrap : public ClapTrap {
	private:

	public:
		// Canonical form
		ScavTrap(void);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap(void);
		//others methods
		ScavTrap(const std::string name);
		void	attack(const std::string& target);
		void	guardGate(void);
};

#endif // SCAVTRAP_HPP
