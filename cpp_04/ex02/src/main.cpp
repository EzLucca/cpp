#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << "[ Test 1: Subject default test ]"			 << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    j->makeSound();

    std::cout << i->getType() << std::endl;
    i->makeSound();

    delete j;
    delete i;

    std::cout << "\n-----------------------------------------"  << std::endl;
    std::cout << "[ Test 2: Deep copy (Dog) ]"					<< std::endl;
    std::cout << "-----------------------------------------"	<< std::endl;

    Dog dog1;
    {
        Dog dog2(dog1); // copy constructor
        std::cout << "Dog2 created by copy constructor" << std::endl;
    } // dog2 destroyed here

    std::cout << "Dog1 still alive after dog2 destruction" << std::endl;

    std::cout << "\n-----------------------------------------"	<< std::endl;
    std::cout << "[ Test 3: Deep copy (assignment operator) ]"	<< std::endl;
    std::cout << "-----------------------------------------"	<< std::endl;

    Dog dog3;
    Dog dog4;

    dog4 = dog3; // copy assignment
    std::cout << "Dog4 assigned from Dog3" << std::endl;

    std::cout << "\n-----------------------------------------"	<< std::endl;
    std::cout << "[ Test 4: Array test (subject-style) ]"		<< std::endl;
    std::cout << "-----------------------------------------"	<< std::endl;

    const int size = 4;
    Animal* animals[size];

    for (int k = 0; k < size; k++) {
        if (k < size / 2)
            animals[k] = new Dog();
        else
            animals[k] = new Cat();
    }

    for (int k = 0; k < size; k++)
        delete animals[k];

    std::cout << "\n-----------------------------------------"	<< std::endl;
    std::cout << "[ All tests done! ]"							<< std::endl;
    std::cout << "-----------------------------------------"	<< std::endl;

    return 0;
}
