#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

template <typename Func>
void testFunction(Func f) {
	try {
		if constexpr (std::is_void_v<decltype(f())>){
			f();
			// std::cout << "Function executed successfully (void)" << std::endl;
		}
		else {
			std::cout << f() << std::endl;
		}
	}
	catch (const std::exception & e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

int main()
{
	{
		std::cout << " ----- Test exceptions ----- \n";

		Span sp = Span(1);
		testFunction([&]() { return sp.addNumber(6);} );
		testFunction([&]() { return sp.shortestSpan(); });
		testFunction([&]() { return sp.longestSpan(); });
		testFunction([&]() { return sp.addNumber(5);} );

		Span jp = Span(0);
		testFunction([&]() { return jp.shortestSpan(); });
		testFunction([&]() { return jp.longestSpan(); });
	}
	{
		std::cout << " ----- Test normal ----- \n";

		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		testFunction([&]() { return sp.shortestSpan(); });
		testFunction([&]() { return sp.longestSpan(); });
	}
	{
		std::cout << " ----- Test 10000 ----- \n";

		Span sp = Span(10000);

		std::srand(static_cast<unsigned int>(std::time(nullptr)));

		for (int i = 0; i < 10000; ++i) {
			int num = std::rand() % 10000;
			sp.addNumber(num);
		}
		testFunction([&]() { return sp.shortestSpan(); });
		testFunction([&]() { return sp.longestSpan(); });
	}
	{
		std::cout << " ----- Test range ----- \n";
		{
			Span sp(5); // Span with capacity 10
			std::vector<int> vec = {1, 2, 3, 4, 5};
			testFunction([&] () { return sp.addNumberRange(vec.begin(), vec.end());} );
			std::cout << "Numbers after adding vector range: ";
			for (int n : sp.getNumbers())
				std::cout << n << " ";
			std::cout << std::endl;
		}
		{
			Span sp(5); // Span with capacity 10
			std::list<int> vec = {1, 2, 3, 4, 5};
			testFunction([&] () { return sp.addNumberRange(vec.begin(), vec.end());} );
			std::cout << "Numbers after adding vector range: ";
			for (int n : sp.getNumbers())
				std::cout << n << " ";
			std::cout << std::endl;
		}
		{
			Span sp(2);
			std::vector<int> bigVec = {6, 7, 8, 9, 10, 11};
			testFunction([&] () { return sp.addNumberRange(bigVec.begin(), bigVec.end());} );
		}
		{
			Span sp(5);
			std::vector<int> vec = {1, 2, 3, 4, 5};
			testFunction([&] () { return sp.addNumberRange(vec.end(), vec.begin());} );
		}
	}
	return 0;
}
