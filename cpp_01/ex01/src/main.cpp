#include "Zombie.hpp"

int main (void) {
	int N = 5;
	Zombie type = Zombie("freed");
	type.announce();
	Zombie *horde = zombieHorde(N, "allocated minion");
	if(horde) {
		for(int i = 0; i < N; i++)
			horde[i].announce();
		delete[](horde);
		return (0);
	}
	return(1);
}
