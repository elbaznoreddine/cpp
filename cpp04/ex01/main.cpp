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

    Cat c;
    Cat c1(c);
    c = c1;
    Cat c10 = c;
    Cat c2(c1);
    c.makeSound();
    c1.makeSound();

    Dog d;
    Dog d1(d);
    d = d1;
    Dog d10 = d;
    Dog d2(d1);
    d.makeSound();
    d1.makeSound();
    return 0;
}