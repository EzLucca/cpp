#include "Zombie.hpp"

/**
 * @brief Default constructor.
 *
 * Creates a Zombie with an empty name.
 */
Zombie::Zombie(void) {}

/**
 * @brief Constructor with a name.
 *
 * Initializes the Zombie with the given name.
 *
 * @param name The name of the Zombie.
 */
Zombie::Zombie(std::string name) : name(name) {}

/**
 * @brief Makes the Zombie announce itself.
 */
void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

/**
 * @brief Set the name of each Zombie in the horde.
 */
void Zombie::setname(std::string name) {
	this->name = name;
}
/**
 * @brief Destructor.
 *
 * Called when the Zombie is destroyed. Prints a message
 * indicating that the Zombie was killed.
 */
Zombie::~Zombie(void) {
	std::cout << "Zombie " << name << " was killed.\n";
}
