#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
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
