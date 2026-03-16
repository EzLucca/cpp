#include "iter.hpp"
#include <cmath>

	template <typename F>
void	print(const F &x)
{
	std::cout << x << " ";
}
	template <typename F>
void	increment(F &x)
{
	x++;
}
	template <typename F>
void	shout(F &x)
{
	x = "One " + x;
}
	template <typename F>
void	uppermachine(F &x)
{
	if(x >= 'a' || x <= 'z') 
		x -= 32;
}

int main(){
	{
		std::cout << "----- INT TEST -----" << "\n";
		int array[] = {1, 2, 3, 4, 5};
		const int array2[] = {11, 22, 33, 44, 55};

		std::cout << "Original: ";
		iter(array, 5, print<int>);
		std::cout << std::endl;

		iter(array, 5, increment<int>);

		std::cout << "Incremented: ";
		iter(array, 5, print<int>);
		std::cout << std::endl;
		iter(array2, 5, print<int>);

	}
	{
		std::cout << "\n----- STRING TEST -----" << "\n";
		std::string strArr[] = {"vanilla ice cream", "freezing coca cola", "good memory!!"};

		std::cout << "Original: ";
		iter(strArr, 3, print<std::string>);
		std::cout << std::endl;

		iter(strArr, 3, shout<std::string>);

		std::cout << "With exclamation: ";
		iter(strArr, 3, print<std::string>);
		std::cout << std::endl;

	}
	{
		std::cout << "\n----- CHAR TEST -----" << "\n";
		char charArr[] = {'a', '7', 'c', 'd'};

		std::cout << "Original: ";
		iter(charArr, 4, print<char>);
		std::cout << std::endl;

		iter(charArr, 4, uppermachine<char>);

		std::cout << "Uppercased: ";
		iter(charArr, 4, print<char>);
		std::cout << std::endl;
	}
	return 0;
}
