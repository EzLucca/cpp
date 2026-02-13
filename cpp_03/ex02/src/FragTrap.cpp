#include "FragTrap.hpp"

// Default constructor calling ClapTrap
FragTrap::FragTrap(void) : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called.\n";
}

// Constructor FragTrap with name variable
FragTrap::FragTrap(const std::string name)
: ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << name << " constructor called.\n";
}

// Copy Constructor FragTrap 
FragTrap::FragTrap(const FragTrap &other)
: ClapTrap(other) {
	std::cout << "FragTrap copy constructor called.\n";
}

// Copy assignment operator FragTrap using ClapTrap operator
FragTrap &FragTrap::operator=(const FragTrap &other) {
	if(this != &other) {
		ClapTrap::operator=(other);
		std::cout << "FragTrap copy assignment operator called.\n";
	}
	return(*this);
}

// Destructor of FragTrap
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap default destructor called for " << this->_name << std::endl;
}

// FragTrap specific function
void	FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name << " request high five.\n";
}
