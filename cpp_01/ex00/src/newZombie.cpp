#include "Zombie.hpp"

Zombie* newZombie(std::string name) {

	try{
		Zombie *dead = new Zombie(name);
		return (dead);
	}
	catch(std::bad_alloc& p){
		std::cerr << "Allocation failed.\n";
		return (nullptr);
	}
}
