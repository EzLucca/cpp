#include "HumanB.hpp"

HumanB::HumanB(std::string nameB) : name(nameB) {}

HumanB::~HumanB() { }

void	HumanB::setWeapon(Weapon &weaponB) {
	weapon = &weaponB;
}

void	HumanB::attack() {
	if(weapon == nullptr) {
		std::cout << name << " fail to attack.\n";
	}
	else {
		std::cout << name << " attacks with the " << weapon->getType() << std::endl;
	}
}
