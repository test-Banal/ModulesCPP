#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // Animal a; // This line will cause a compilation error because Animal is an abstract class
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " : Dog  " << std::endl;
    std::cout << i->getType() << " : Cat  " << std::endl;
    //std::cout <<  " Dog sound : Woof : result : " << std::endl;
    j->makeSound(); //will output the cat sound!
    //std::cout << " Cat sound : Meow : result : " << std::endl;
    i->makeSound(); //will output the dog sound!
    meta->makeSound(); //will output the generic animal sound!

    delete meta;
    delete j;
    delete i;

    return 0;
}



