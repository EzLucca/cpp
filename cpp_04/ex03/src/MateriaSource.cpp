#include "MateriaSource.hpp"

/**
 * @brief Default constructor.
 *
 * Initializes the storage array with NULL pointers.
 * No Materia is stored initially.
 */
MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        _storage[i] = 0;
}

/**
 * @brief Copy constructor.
 *
 * Performs a deep copy of another MateriaSource. All stored Materia
 * in the source are cloned into the new instance.
 *
 * @param other The MateriaSource instance to copy.
 */
MateriaSource::MateriaSource(const MateriaSource &other) : IMateriaSource() {
    for (int i = 0; i < 4; i++)
        _storage[i] = 0;
    *this = other;
}

/**
 * @brief Copy assignment operator.
 *
 * Deletes any existing Materia in the storage, then performs a deep copy
 * of the source MateriaSource. Each stored Materia is cloned.
 *
 * @param other The MateriaSource instance to assign from.
 * @return Reference to the assigned object.
 */
MateriaSource &MateriaSource::operator=(const MateriaSource &other) {
	if (this != &other) {
		for (int i = 0;i < 4; i++) {
			delete _storage[i];
			_storage[i] = other._storage[i] ? other._storage[i]->clone() : nullptr;
		}
	}
	return(*this);
}

/**
 * @brief Destructor.
 *
 * Deletes all stored Materia to avoid memory leaks.
 */
MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete _storage[i];
}

/**
 * @brief Learns a new Materia.
 *
 * Clones the provided Materia and stores it in the first available slot.
 * If storage is full or the pointer is NULL, the Materia is ignored.
 *
 * @param m Pointer to the AMateria to learn.
 */
void	MateriaSource::learnMateria(AMateria* m) {
	if(!m)
		return ;
	for (int i = 0;i < 4;i++) {
		if(!_storage[i]) {
			_storage[i] = m->clone();
			return ;
		}
	}
}

/**
 * @brief Creates a Materia of the given type.
 *
 * Searches the stored Materia for one matching the given type.
 * Returns a newly allocated clone if found, or NULL otherwise.
 *
 * @param type The type of Materia to create.
 * @return Pointer to a new AMateria instance, or NULL if not found.
 */
AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0;i < 4;i++) {
		if(_storage[i] && _storage[i]->getType() == type)
			return (_storage[i]->clone());
	}
	return 0;
}
