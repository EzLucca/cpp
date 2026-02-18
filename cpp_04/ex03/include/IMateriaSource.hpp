#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"

/**
 * @brief Interface for Materia source objects.
 *
 * IMateriaSource defines the contract for classes capable of
 * storing and creating AMateria objects. Implementing classes
 * are responsible for managing the storage and lifetime of
 * learned Materia instances.
 *
 * This class is an interface:
 * - It contains only pure virtual methods
 * - It has no data members
 * - It cannot be instantiated directly
 */
class IMateriaSource {
	private:

	public:
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource &other);
		IMateriaSource &operator=(const IMateriaSource &other);
		virtual ~IMateriaSource(void);
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif // IMATERIASOURCE_HPP
