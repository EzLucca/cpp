#include "FragTrap.hpp"

/**
 * @brief Default constructor.
 *
 * Calls ClapTrap default constructor, then sets FragTrap-specific stats:
 * hitPoints = 100, energyPoints = 100, attackDamage = 30.
 */
FragTrap::FragTrap(void) : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called.\n";
}

/**
 * @brief Constructor with a custom name.
 *
 * Calls ClapTrap constructor with name and sets FragTrap-specific stats:
 * hitPoints = 100, energyPoints = 100, attackDamage = 30.
 *
 * @param name Name of the FragTrap.
 */
FragTrap::FragTrap(const std::string name)
: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called.\n";
}

/**
 * @brief Copy constructor.
 *
 * Calls ClapTrap copy constructor.
 *
 * @param other FragTrap instance to copy.
 */
FragTrap::FragTrap(const FragTrap &other)
: ClapTrap(other) {
	std::cout << "FragTrap copy constructor called.\n";
}

/**
 * @brief Copy assignment operator.
 *
 * Uses ClapTrap assignment operator and outputs a message.
 *
 * @param other FragTrap instance to assign from.
 * @return Reference to this FragTrap.
 */
FragTrap &FragTrap::operator=(const FragTrap &other) {
	if(this != &other) {
		ClapTrap::operator=(other);
		std::cout << "FragTrap copy assignment operator called.\n";
	}
	return(*this);
}

/**
 * @brief Destructor.
 *
 * Cleans up the FragTrap instance.
 */
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap default destructor called for " << this->_name << std::endl;
}

/**
 * @brief FragTrap-specific function to request a high five.
 *
 * Prints a message requesting a high five.
 */
void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " request high five.\n";
}
