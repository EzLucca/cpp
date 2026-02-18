#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

/**
 * @brief Concrete implementation of IMateriaSource.
 *
 * MateriaSource stores up to 4 learned AMateria objects and can
 * create new Materia instances based on the learned types.
 * It implements the IMateriaSource interface.
 *
 * Responsibilities:
 * - Manage Materia storage and ownership
 * - Clone learned Materia when creating new instances
 */
class MateriaSource : public IMateriaSource {
	private:
		AMateria* _storage[4];

	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &other);
		MateriaSource &operator=(const MateriaSource &other);
		virtual ~MateriaSource(void);

		virtual void learnMateria(AMateria* m);
		virtual	AMateria* createMateria(std::string const& type);
};

#endif // MATERIASOURCE_HPP
