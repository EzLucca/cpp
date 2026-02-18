#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/**
 * @class Dog
 * @brief Represents a dog with a dynamically allodoged brain, derived from Animal.
 *
 * The Dog class specializes the Animal class by providing a dog-specific
 * implementation of makeSound() and contains a Brain object to store ideas.
 */
class Dog : public Animal {
	private:
		Brain* _dogBrain;

	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		virtual ~Dog(void);

		virtual void	makeSound(void) const;
};

#endif // DOG_HPP
