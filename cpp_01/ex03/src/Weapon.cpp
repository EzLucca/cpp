#include "Weapon.hpp"

Weapon::Weapon(std::string name) {
	type = name;	
}

void	Weapon::setType(std::string typeWeapon) {
	type = typeWeapon;
}

const std::string &Weapon::getType(void) const{
	return(type);
}

Weapon::~Weapon() {}
