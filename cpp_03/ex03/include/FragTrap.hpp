#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/**
 * @brief Class representing a FragTrap robot.
 *
 * Inherits virtually from ClapTrap. FragTraps have higher stats and 
 * a special function to request high fives.
 */
class FragTrap : virtual public ClapTrap {
	private:

	public:
		// Canonical form
		FragTrap(void);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap(void);
		//others methods
		FragTrap(const std::string name);
		void	highFivesGuys(void);
};

#endif // FRAGTRAP_HPP
