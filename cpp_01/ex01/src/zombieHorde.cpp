#include "Zombie.hpp"

/**
 * @brief Creates a horde of Zombies on the heap.
 *
 * Allocates an array of N Zombies on the heap. Each Zombie is given a
 * unique name by appending a number to the base name (e.g., "Zombie1", "Zombie2").
 * The caller is responsible for deleting the array using `delete[]` to avoid memory leaks.
 * If N is less than or equal to 0, or allocation fails, the function returns nullptr.
 *
 * @param N The number of Zombies to create.
 * @param name The base name for the Zombies.
 * @return Pointer to the first Zombie in the array, or nullptr if allocation fails or N <= 0.
 */
Zombie* zombieHorde(int N, std::string name) {
    if (N <= 0)
        return nullptr;
    try {
        Zombie *hordofdead = new Zombie[N];
        for (int i = 0; i < N; i++)
            hordofdead[i].setname(name + std::to_string(i + 1));
        return hordofdead;
    }
    catch (std::bad_alloc& e) {
        std::cerr << "Allocation failed.\n";
        return nullptr;
    }
}
