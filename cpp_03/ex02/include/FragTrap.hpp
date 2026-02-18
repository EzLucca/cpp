#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/**
 * @brief Class representing a FragTrap robot.
 *
 * Inherits from ClapTrap. FragTraps have enhanced behavior such as
 * requesting high fives.
 */
class FragTrap : public ClapTrap {
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
