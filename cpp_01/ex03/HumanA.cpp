#include "HumanA.hpp"

HumanA::HumanA(std::string nameA, Weapon &weaponA) : name(nameA), weapon(weaponA) {}

void	HumanA::attack() {
	std::cout << name << " attacks with the " << weapon.getType() << std::endl;
}

HumanA::~HumanA() {}
