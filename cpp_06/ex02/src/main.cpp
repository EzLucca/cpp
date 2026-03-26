#include <ctime>
#include <cstdlib>
#include "Aclass.hpp"
#include "Base.hpp"
#include "Bclass.hpp"
#include "Cclass.hpp"

class Dclass : public Base {};

int	main () {
	std::srand(std::time(nullptr));
	{
		std::cout << "\n----- Create 10 objects and identify them -----\n";
		for(int i = 0; i < 10;i++){

			std::cout << "Object " << i + 1 << " created\n";
			Base* object = generate();
			// Base* unknown = new Dclass();

			std::cout << "Object pointer: ";
			identify(object);
			std::cout << "Object reference: ";
			identify(*object);
			// identify(unknown);
			std::cout << "\n";
			delete object;
			// delete unknown;
		}
		return 0;
	}
}
