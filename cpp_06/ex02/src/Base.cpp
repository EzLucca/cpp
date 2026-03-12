#include "Aclass.hpp"
#include "Base.hpp"
#include "Bclass.hpp"
#include "Cclass.hpp"

Base	*generate(void){
	int	random = std::rand() % 3;

	switch (random) {
		case 0:
			std::cout << "Instanciate Class A\n";
			return new Aclass();
		case 1:
			std::cout << "Instanciate Class B\n";
			return new Bclass();
		case 2:
			std::cout << "Instanciate Class C\n";
			return new Cclass();
	}
	return nullptr;
}

void	identify(Base* p){
	if (!p) {
		std::cout << "nullpoiter\n";
		return;
	}
	if (dynamic_cast<Aclass*>(p)){
		std::cout << "Type Class A\n";
	}
	else if (dynamic_cast<Bclass*>(p)){
		std::cout << "Type Class B\n";
	}
	else if (dynamic_cast<Cclass*>(p)){
		std::cout << "Type Class C\n";
	}
	else {
		std::cout << "Unknown class\n";
	}
}

void	identify(Base& p){
	try {
		(void)dynamic_cast<Aclass&>(p);
		std::cout << "Type Class A\n";
		return ;
	}
	catch (std::bad_cast){}

	try {
		(void)dynamic_cast<Bclass&>(p);
		std::cout << "Type Class B\n";
		return ;
	}
	catch (std::bad_cast){}

	try {
		(void)dynamic_cast<Cclass&>(p);
		std::cout << "Type Class C\n";
		return ;
	}
	catch (std::bad_cast){}
}
