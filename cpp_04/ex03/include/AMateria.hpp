#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

/**
 * @brief Abstract base class for all Materia types.
 *
 * AMateria represents a magical material that can be used
 * by characters. It defines common behavior and attributes
 * shared by all concrete Materia classes (such as Ice or Cure).
 *
 * This class is abstract:
 * - It cannot be instantiated directly
 * - Derived classes must implement the clone() method
 */
class AMateria {
	protected:
		std::string _type;

	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria &other);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria(void);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif // AMATERIA_HPP
