#include "Zombie.hpp"

Zombie::Zombie() {}
Zombie::Zombie(std::string name) : name(name) {}

void	Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setname(std::string name) {
	this->name = name;

}

Zombie::~Zombie() {
	std::cout << "Zombie " << name <<  " was killed.\n";
}
