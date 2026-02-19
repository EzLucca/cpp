#include "Zombie.hpp"

/**
 * @brief Default constructor.
 *
 * Creates a Zombie with an empty name.
 */
Zombie::Zombie() {}

/**
 * @brief Constructor with a name.
 *
 * Initializes the Zombie with the given name.
 *
 * @param name The name of the Zombie.
 */
Zombie::Zombie(std::string name) : _name(name) {}

/**
 * @brief Makes the Zombie announce itself.
 */
void Zombie::announce() const {
    std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}

/**
 * @brief Destructor.
 *
 * Called when the Zombie is destroyed. Prints a message
 * indicating that the Zombie was killed.
 */
Zombie::~Zombie() {
    std::cout << "Zombie " << _name << " was killed.\n";
}
