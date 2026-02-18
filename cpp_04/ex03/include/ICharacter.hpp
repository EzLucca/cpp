#ifndef ICHARACTER_HPP
#define ICHARACTER_HPP

#include <iostream>

class AMateria;

/**
 * @brief Interface representing a character that can use Materia.
 *
 * ICharacter defines the contract for character classes capable of
 * equipping, unequipping, and using AMateria objects. Implementing
 * classes are responsible for managing Materia storage and behavior.
 *
 * This class is an interface:
 * - It contains only pure virtual methods
 * - It has no data members
 * - It cannot be instantiated directly
 */
class ICharacter {
	private:

	public:
		virtual ~ICharacter(void);

		virtual std::string const & getName() const = 0;
		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;
};

#endif // ICHARACTER_HPP
