#include "Zombie.hpp"

/**
 * @brief Creates a temporary Zombie on the stack and makes it announce itself.
 *
 * This function creates a Zombie with the given name on the stack,
 * calls its `announce()` method, and then automatically destroys
 * it when the function returns.
 *
 * @param name The name of the Zombie.
 */
void	randomChump(std::string name) {
	Zombie dead(name); 
	dead.announce();
}
