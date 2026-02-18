#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

/**
 * @class Cat
 * @brief Represents a cat, derived from the Animal base class.
 *
 * The Cat class specializes the Animal class by providing
 * a cat-specific implementation of the makeSound() method.
 */
class Cat : public Animal{
	private:

	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat(void) override;

		void	makeSound(void) const override;
};

#endif // CAT_HPP
