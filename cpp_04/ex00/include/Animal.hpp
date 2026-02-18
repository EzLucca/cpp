#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

/**
 * @class Animal
 * @brief Base class representing a generic animal.
 *
 * The Animal class serves as a base class for derived animal types.
 * It stores the animal type and provides a virtual interface for
 * making sounds.
 */
class Animal {
	protected:
		std::string _type;
	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal(void);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif // ANIMAL_HPP
