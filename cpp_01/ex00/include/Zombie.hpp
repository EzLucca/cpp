#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <new>

/**
 * @brief Class representing a Zombie.
 *
 * A Zombie has a name and can announce itself.
 * Zombies can be created on the stack or the heap.
 */
class Zombie {
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();
	void announce(void) const;

private:
	std::string name;
};

/**
 * @brief Creates a new Zombie on the heap.
 *
 * Allocates a Zombie with the given name and returns a pointer.
 * Caller is responsible for deleting the Zombie to avoid memory leaks.
 *
 * @param name The name of the Zombie.
 * @return Pointer to the newly created Zombie.
 */
Zombie* newZombie(std::string name);

/**
 * @brief Creates a temporary Zombie on the stack and makes it announce itself.
 *
 * The Zombie is automatically destroyed when the function returns.
 *
 * @param name The name of the Zombie.
 */
void	randomChump(std::string name);

#endif // ZOMBIE_HPP
