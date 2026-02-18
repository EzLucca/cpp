#include "Zombie.hpp"

/**
 * @brief Creates a new Zombie on the heap.
 *
 * Allocates a Zombie with the given name and returns a pointer.
 * The caller is responsible for deleting the Zombie to avoid memory leaks.
 * If allocation fails, the function prints an error and returns nullptr.
 *
 * @param name The name of the Zombie.
 * @return Pointer to the newly created Zombie, or nullptr if allocation fails.
 */
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
