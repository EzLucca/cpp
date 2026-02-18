#include "DiamondTrap.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes a DiamondTrap with a default name.
 * Stats are composed from parent classes:
 * - hitPoints from FragTrap
 * - energyPoints from ScavTrap
 * - attackDamage from FragTrap
 *
 * The ClapTrap base name is set to "<DiamondName>_clap_name".
 */
DiamondTrap::DiamondTrap(void)
	: _name("Default Diamond")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	ClapTrap::_name = _name + "_clap_name";
	std::cout << "DiamondTrap Default constructor called.\n";
}

/**
 * @brief Constructor with name parameter.
 *
 * Initializes:
 * - ClapTrap base with name + "_clap_name"
 * - ScavTrap and FragTrap bases
 * - DiamondTrap own name
 *
 * Stats are combined from parent classes:
 * - hitPoints from FragTrap
 * - energyPoints from ScavTrap
 * - attackDamage from FragTrap
 *
 * @param name Name of the DiamondTrap.
 */
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

/**
 * @brief Copy constructor.
 *
 * Copies all base class parts and the DiamondTrap name.
 *
 * @param other DiamondTrap instance to copy.
 */
DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other),
	ScavTrap(other),
	FragTrap(other),
	_name(other._name)
{
	std::cout << "DiamondTrap " << _name << " copy constructor called.\n";
}

/**
 * @brief Copy assignment operator.
 *
 * Assigns the DiamondTrap name and uses ClapTrap assignment
 * to copy shared base members.
 *
 * @param other DiamondTrap instance to assign from.
 * @return Reference to this DiamondTrap.
 */
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other) {
		this->_name = other._name;
		ClapTrap::operator=(other);
	}
	return (*this);
}

/**
 * @brief Destructor.
 *
 * Cleans up the DiamondTrap instance.
 */
DiamondTrap::~DiamondTrap(void) {
	std::cout << "Diamond " << _name << " destructor called.\n";
}

/**
 * @brief Displays the identity of the DiamondTrap.
 *
 * Prints:
 * - The DiamondTrap's own name
 * - The inherited ClapTrap base name
 */
void	DiamondTrap::whoAmI(void) {
	std::cout << "DiamondTrap name: " <<_name << std::endl
		<< "ClapTrap name: " << ClapTrap::_name << std::endl;
}
