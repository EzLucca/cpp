#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

/**
 * @brief Concrete Materia of type "cure".
 *
 * Cure is a concrete implementation of AMateria that represents
 * a healing Materia. It provides its own implementation of
 * cloning and usage behavior.
 */
class Cure : public AMateria {
	private:

	public:
		Cure(void);
		Cure(const Cure &other);
		Cure &operator=(const Cure &other);
		virtual ~Cure(void);

		virtual AMateria* clone() const;
		virtual void	use(ICharacter& target);
};

#endif // CURE_HPP
