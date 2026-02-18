#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

/**
 * @class Dog
 * @brief Represents a dog, derived from the Animal base class.
 *
 * The Dog class specializes the Animal class by providing
 * a dog-specific implementation of the makeSound() method.
 */
class Dog : public Animal {
	private:

	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog(void) override;

		void	makeSound(void) const override;
};

#endif // DOG_HPP
