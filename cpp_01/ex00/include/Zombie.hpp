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
	private:
		std::string _name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce(void) const;

};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif // ZOMBIE_HPP
