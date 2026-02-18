#include "ClapTrap.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes a ClapTrap with default name and stats:
 * hitPoints = 10, energyPoints = 10, attackDamage = 0.
 */
ClapTrap::ClapTrap(void) :
	_name("default"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
		std::cout << "ClapTrap default constructor created.\n";
	}

/**
 * @brief Destructor.
 *
 * Cleans up the ClapTrap instance.
 */
ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap default destructor created.\n";
}

/**
 * @brief Constructor with a custom name.
 *
 * Initializes ClapTrap with specified name and default stats.
 *
 * @param name Name of the ClapTrap.
 */
ClapTrap::ClapTrap(const std::string name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
		std::cout << "ClapTrap " << name << " constructor created.\n";
	}

/**
 * @brief Copy constructor.
 *
 * Creates a new ClapTrap as a copy of another.
 *
 * @param other ClapTrap instance to copy.
 */
ClapTrap::ClapTrap(const ClapTrap &other) : 
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage) {
		std::cout << "ClapTrap copy constructor created.\n";
	}

/**
 * @brief Copy assignment operator.
 *
 * Assigns values from another ClapTrap instance.
 *
 * @param other ClapTrap instance to copy from.
 * @return Reference to this ClapTrap.
 */
ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	if(this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "ClapTrap copy assignment operator.\n";
	}
	return (*this);
}

/**
 * @brief Makes the ClapTrap attack a target.
 *
 * Consumes 1 energy point. Cannot attack if hitPoints or energyPoints are 0.
 *
 * @param target The target to attack.
 */
void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name
			<< " has no hitPoints. Cannot attack.\n";
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name
			<< " has no energyPoints. Cannot attack.\n";
		return ;
	}
	--_energyPoints;
	std::cout << "ClapTrap " << _name
		<< " attacks " << target 
		<< ", causing " << _attackDamage << " points of damage!\n";
};

/**
 * @brief Reduces the ClapTrap's hit points.
 *
 * Hit points cannot drop below 0. Prints status messages.
 *
 * @param amount Damage amount to apply.
 */
void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name
			<< " has no hitPoints left.\n";
		return ;
	}
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name
			<< " has no more hitPoints.\n";
		return ;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name
		<< " take " << amount 
		<< " of damage points\n";
}

/**
 * @brief Repairs the ClapTrap by a given amount.
 *
 * Consumes 1 energy point. Cannot repair if hitPoints or energyPoints are 0.
 *
 * @param amount Hit points to restore.
 */
void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << _name
			<< " has no hitPoints and is already dead.\n";
		return ;
	}
	if (_energyPoints <= 0) {
		std::cout << "ClapTrap " << _name
			<< " has no energyPoints left. Cannot repair.\n";
		return ;
	}
	--_energyPoints;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name
		<< " repairs " << amount 
		<< " hitpoints\n";
}
