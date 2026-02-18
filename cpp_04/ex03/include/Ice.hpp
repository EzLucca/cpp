#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

/**
 * @brief Concrete Materia of type "ice".
 *
 * Ice is a concrete implementation of AMateria that represents
 * an ice-based attack Materia. It provides specific implementations
 * of cloning and usage behavior.
 */
class Ice : public AMateria {
	private:

	public:
		Ice(void);
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		virtual ~Ice(void);

		virtual AMateria* clone() const;
		virtual void	use(ICharacter& target);
};

#endif // ICE_HPP
