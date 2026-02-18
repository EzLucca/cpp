#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

/**
 * @class Brain
 * @brief Represents the brain of an animal, storing ideas.
 *
 * The Brain class contains an array of 100 strings representing
 * ideas or thoughts. It is typically used as a member of Animal-derived classes.
 */
class Brain {
	private:
		std::string	_ideas[100];

	public:
		Brain(void);
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain(void);

};

#endif // BRAIN_HPP
