#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/**
 * @class Cat
 * @brief Represents a cat with a dynamically allocated brain, derived from Animal.
 *
 * The Cat class specializes the Animal class by providing a cat-specific
 * implementation of makeSound() and contains a dynamically allocated Brain
 * object to store ideas. Proper deep copy is implemented in copy constructor
 * and assignment operator.
 */
class Cat : public Animal{
	private:
		Brain* _catBrain;

	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat(void);

		virtual void	makeSound(void) const;
		// void	makeSound(void) const;
};

#endif // CAT_HPP
