#include "DiamondTrap.hpp"

// Default constructor for DiamondTrap
DiamondTrap::DiamondTrap(void)
	: _name("Default Diamond")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "DiamondTrap Default constructor called.\n";
}

// Constructor with name as parameter
DiamondTrap::DiamondTrap(const std::string name)
	: ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	_name(name)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << name << " constructor called.\n";
}

// copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	_name(other._name)
{
	std::cout << "DiamondTrap " << _name << " copy constructor called.\n";
}

// copy assignment operator
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		ClapTrap::operator=(other);
	}
	return (*this);
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "Diamond " << _name << " destructor called.\n";
}

void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name: " <<_name << std::endl
		<< "ClapTrap name: " << ClapTrap::_name << std::endl;
}
