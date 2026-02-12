#include "ScavTrap.hpp"

// Default constructor calling ClapTrap
ScavTrap::ScavTrap(void) : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called.\n";
}

// Constructor ScavTrap with name variable
ScavTrap::ScavTrap(const std::string name)
: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << name << " constructor called.\n";
}

// Copy Constructor ScavTrap 
ScavTrap::ScavTrap(const ScavTrap &other)
: ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called.\n";
}

// Copy assignment operator ScavTrap using ClapTrap operator
ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	if(this != &other) {
		ClapTrap::operator=(other);
		std::cout << "ScavTrap copy assignment operator called.\n";
	}
	return(*this);
}

// Destructor of ScavTrap
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap default destructor called for " << this->_name << std::endl;
}

// ScavTrap attack function
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

// ScavTrap specific function
void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << _name << " invoke gate keeper mode.\n";
}
