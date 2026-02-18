#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

/**
 * @class WrongAnimal
 * @brief Base class demonstrating incorrect use of polymorphism.
 *
 * The WrongAnimal class is similar to Animal but intentionally
 * does not use virtual functions.
 */
class WrongAnimal {
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		~WrongAnimal(void);

		std::string		getType(void) const;
		void			makeSound(void) const;
};

#endif // WRONGANIMAL_HPP
