#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ){
	if (N <= 0)
		return (nullptr);
	try{
		Zombie *hordofdead = new Zombie[N];
		for(int i = 0; i < N; i++)
			hordofdead[i].setname(name + std::to_string(i + 1));
		return (hordofdead);
	}
	catch(std::bad_alloc& p){
		std::cerr << "Allocation failed.\n";
		return (nullptr);
	}
}
