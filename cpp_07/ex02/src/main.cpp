#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}

	// printing the 10 numbers
	for (int i = 0; i < 10; i++)
	{
		std::cout << "number["<< i << "]: "<< numbers[i] << "\n";
	}

	// testing out of bounds values
	try
	{
		std::cout << -2 << ": "<< numbers[-2] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
	try
	{
		std::cout << "number[749]: "<< numbers[749] << "\n";
		std::cout << "number["<< MAX_VAL << "]: "<< numbers[MAX_VAL] << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << "number array[749]:" << numbers[749] << "\n";
	std::cout << "mirror array[749]:" << mirror[749] << "\n";
	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout << "number array[749]:" << numbers[749] << "\n";
	std::cout << "mirror array[749]:" << mirror[749] << "\n";
	delete [] mirror;//
	return 0;
}
