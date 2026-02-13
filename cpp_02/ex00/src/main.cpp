#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;
	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;

	std::cout << "reseting raw value = 4\n\n";
	a.setRawBits(4);
	Fixed d( a );
	Fixed e;
	e = d;
	std::cout << "_raw = 4\n\n";
	std::cout << a.getRawBits() << std::endl;
	std::cout << d.getRawBits() << std::endl;
	std::cout << e.getRawBits() << std::endl;
	return 0;
}
