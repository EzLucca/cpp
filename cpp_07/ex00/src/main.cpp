#include <iostream>
#include <string>
#include "Whatever.hpp"


int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

// int main(){
// 	{
// 		std::cout << "----- String test ------\n";
//
// 		std::string string1 = "string1";
// 		std::string string2 = "another string";
//
// 		std::cout << "string1:  " << string1 << "\n";
// 		std::cout << "string2 : " << string2 << "\n";
//
// 		::swap(string1, string2);
//
// 		std::cout << "string1:  " << string1 << "\n";
// 		std::cout << "string2 : " << string2 << "\n";
// 		std::cout << "min(string1, string2) = " << ::min(string1, string2) << "\n";
// 		std::cout << "max(string1, string2) = " << ::max(string1, string2) << "\n";
// 	}
// 	{
// 		std::cout << "----- Int test ------\n";
//
// 		int a = 2;
// 		int b = 6;
//
// 		std::cout << "a:  " << a << "\n";
// 		std::cout << "b : " << b << "\n";
//
// 		::swap(a, b);
//
// 		std::cout << "a:  " << a << "\n";
// 		std::cout << "b : " << b << "\n";
// 		std::cout << "min(a, b) = " << ::min(a, b) << "\n";
// 		std::cout << "max(a, b) = " << ::max(a, b) << "\n";
//
// 	}
// 	{
// 		std::cout << "----- Double test ------\n";
//
// 		double a = 2.7272828;
// 		double b = -6.0050003;
//
// 		std::cout << "a:  " << a << "\n";
// 		std::cout << "b : " << b << "\n";
//
// 		::swap(a, b);
//
// 		std::cout << "a:  " << a << "\n";
// 		std::cout << "b : " << b << "\n";
// 		std::cout << "min(a, b) = " << ::min(a, b) << "\n";
// 		std::cout << "max(a, b) = " << ::max(a, b) << "\n";
// 	}
// 	{
// 		std::cout << "----- Float test ------\n";
//
// 		float a = 2.7272828f;
// 		float b = -6.0050003f;
//
// 		std::cout << "a:  " << a << "\n";
// 		std::cout << "b : " << b << "\n";
//
// 		::swap(a, b);
//
// 		std::cout << "a:  " << a << "\n";
// 		std::cout << "b : " << b << "\n";
// 		std::cout << "min(a, b) = " << ::min(a, b) << "\n";
// 		std::cout << "max(a, b) = " << ::max(a, b) << "\n";
// 	}
// }
