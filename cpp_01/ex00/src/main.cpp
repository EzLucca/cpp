#include "Zombie.hpp"

int main (void) {
	Zombie type = Zombie("freed");
	type.announce();
	Zombie *dead = newZombie("dinamicZombie");
	if(!dead)
		return(1);
	dead->announce();
	randomChump("randomZombie");
	delete(dead);
	return (0);
}
