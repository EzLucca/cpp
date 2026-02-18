#include "ScavTrap.hpp"

/**
 * @brief Default constructor.
 *
 * Calls ClapTrap default constructor, then sets ScavTrap-specific stats:
 * hitPoints = 100, energyPoints = 50, attackDamage = 20.
 */
ScavTrap::ScavTrap(void) : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called.\n";
}

/**
 * @brief Constructor with a custom name.
 *
 * Calls ClapTrap constructor with name and sets ScavTrap-specific stats:
 * hitPoints = 100, energyPoints = 50, attackDamage = 20.
 *
 * @param name Name of the ScavTrap.
 */
ScavTrap::ScavTrap(const std::string name)
: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called.\n";
}

/**
 * @brief Copy constructor.
 *
 * Calls ClapTrap copy constructor.
 *
 * @param other ScavTrap instance to copy.
 */
ScavTrap::ScavTrap(const ScavTrap &other)
: ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called.\n";
}

/**
 * @brief Copy assignment operator.
 *
 * Uses ClapTrap assignment operator and outputs a message.
 *
 * @param other ScavTrap instance to assign from.
 * @return Reference to this ScavTrap.
 */
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if(this != &other) {
		ClapTrap::operator=(other);
		std::cout << "ScavTrap copy assignment operator called.\n";
	}
	return(*this);
}

/**
 * @brief Destructor.
 *
 * Cleans up the ScavTrap instance.
 */
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap default destructor called for " << this->_name << std::endl;
}

/**
 * @brief Makes the ScavTrap attack a target.
 *
 * Consumes 1 energy point. Cannot attack if hitPoints or energyPoints are 0.
 * Overrides ClapTrap attack.
 *
 * @param target The name of the target to attack.
 */
void	ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout << "ScavTrap " << _name
			<< " has no hitPoints. Cannot attack.\n";
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "ScavTrap " << _name
			<< " has no energyPoints. Cannot attack.\n";
		return ;
	}
	--_energyPoints;
	std::cout << "ScavTrap " << _name
		<< " attacks " << target 
		<< ", causing " << _attackDamage << " points of damage!\n";
}

/**
 * @brief Activates Gate Keeper mode.
 *
 * Prints a message indicating that ScavTrap is now in guard mode.
 */
void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " invoke gate keeper mode.\n";
}
