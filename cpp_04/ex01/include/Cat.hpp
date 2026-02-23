#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

/**
 * @class Cat
 * @brief Represents a cat with a dynamically allocated brain, derived from Animal.
 *
 * The Cat class specializes the Animal class by providing a cat-specific
 * implementation of makeSound() and contains a Brain object to store ideas.
 */
class Cat : public Animal{
	private:
		Brain* _catBrain;

	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		~Cat(void) override;

		void	makeSound(void) const override;
		Brain* getBrain() const;
};

#endif // CAT_HPP
