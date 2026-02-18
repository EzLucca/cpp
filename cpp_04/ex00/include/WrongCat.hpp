#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

/**
 * @class WrongCat
 * @brief Represents a cat derived from WrongAnimal.
 *
 * The WrongCat class attempts to override makeSound(),
 * but due to the absence of virtual functions in
 * WrongAnimal, polymorphism will not work as expected.
 */
class WrongCat : public WrongAnimal {
	private:

	public:
		WrongCat(void);
		WrongCat(std::string type);
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		~WrongCat(void);

		void	makeSound(void) const;
};

#endif // WRONGCAT_HPP
