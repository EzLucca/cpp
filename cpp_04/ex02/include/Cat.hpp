#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private:
		Brain* _catBrain;

	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat(void);

		virtual void	makeSound(void) const;
};

#endif // CAT_HPP
