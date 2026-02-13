#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) :
	_name("default"),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
		std::cout << "ClapTrap default constructor created.\n";
	}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap default destructor created.\n";
}

ClapTrap::ClapTrap(const std::string name) :
	_name(name),
	_hitPoints(10),
	_energyPoints(10),
	_attackDamage(0) {
		std::cout << "ClapTrap " << name << " constructor created.\n";
	}

ClapTrap::ClapTrap(const ClapTrap &other) : 
	_name(other._name),
	_hitPoints(other._hitPoints),
	_energyPoints(other._energyPoints),
	_attackDamage(other._attackDamage) {
		std::cout << "ClapTrap copy constructor created.\n";
	}

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
