#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{    
    int array_size = 100;
    Animal* animals[array_size];

    for (int i = 0; i < array_size / 2; ++i)
	{
        animals[i] = new Dog("Dog");
    }
    for (int i = array_size / 2; i < array_size; ++i) {
        animals[i] = new Cat("Cat");
    }
	
    for (int i = 0; i < array_size; ++i) {
        std::cout << animals[i]->getType() << ": ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < array_size; ++i) {
        delete animals[i];
    }

    return 0;
}