#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

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
