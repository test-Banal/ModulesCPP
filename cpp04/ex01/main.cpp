#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
    std::cout << "========== Test des classes de base Animal ==========\n" << std::endl;
    
    // Test des constructeurs
    std::cout << "--- Création des objets ---" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\n--- Test getType() ---" << std::endl;
    std::cout << "Type de j: " << j->getType() << std::endl;
    std::cout << "Type de i: " << i->getType() << std::endl;
    std::cout << "Type de meta: " << meta->getType() << std::endl;
    
    std::cout << "\n--- Test makeSound() ---" << std::endl;
    std::cout << "Sound de i (Cat): ";
    i->makeSound();
    std::cout << "Sound de j (Dog): ";
    j->makeSound();
    std::cout << "Sound de meta (Animal): ";
    meta->makeSound();
    
    // Test des destructeurs
    std::cout << "\n--- Destruction des objets ---" << std::endl;
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n========== Test des classes WrongAnimal ==========\n" << std::endl;
    
    // Test avec WrongAnimal et WrongCat
    std::cout << "--- Création des objets Wrong ---" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    
    std::cout << "\n--- Test getType() ---" << std::endl;
    std::cout << "Type de wrongMeta: " << wrongMeta->getType() << std::endl;
    std::cout << "Type de wrongCat: " << wrongCat->getType() << std::endl;
    
    std::cout << "\n--- Test makeSound() ---" << std::endl;
    std::cout << "Sound de wrongMeta (WrongAnimal): ";
    wrongMeta->makeSound();
    std::cout << "Sound de wrongCat (WrongCat as WrongAnimal): ";
    wrongCat->makeSound(); // Devrait produire le son de WrongAnimal et non de WrongCat
    
    // Test direct avec WrongCat
    std::cout << "\n--- Test direct avec WrongCat ---" << std::endl;
    const WrongCat* directWrongCat = new WrongCat();
    std::cout << "Sound de directWrongCat (WrongCat direct): ";
    directWrongCat->makeSound(); // Ici, makeSound de WrongCat est utilisé directement
    
    // Test des destructeurs
    std::cout << "\n--- Destruction des objets Wrong ---" << std::endl;
    delete wrongMeta;
    delete wrongCat;
    delete directWrongCat;
    
    // Test supplémentaire - Création sur la pile
    std::cout << "\n========== Test supplémentaire - Objets sur la pile ==========\n" << std::endl;
    
    std::cout << "--- Création des objets sur la pile ---" << std::endl;
    Animal animalOnStack;
    Dog dogOnStack;
    Cat catOnStack;
    
    std::cout << "\n--- Test makeSound() sur la pile ---" << std::endl;
    std::cout << "Sound de animalOnStack: ";
    animalOnStack.makeSound();
    std::cout << "Sound de dogOnStack: ";
    dogOnStack.makeSound();
    std::cout << "Sound de catOnStack: ";
    catOnStack.makeSound();
    
    // Les objets sur la pile seront détruits automatiquement à la fin de la portée
    std::cout << "\n--- Fin du programme (destruction automatique des objets sur la pile) ---" << std::endl;
    
    return 0;
}

// int main()
// {
//     // Animal a; // This line will cause a compilation error because Animal is an abstract class
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();

//     std::cout << j->getType() << " : Dog  " << std::endl;
//     std::cout << i->getType() << " : Cat  " << std::endl;
//     //std::cout <<  " Dog sound : Woof : result : " << std::endl;
//     j->makeSound(); //will output the cat sound!
//     //std::cout << " Cat sound : Meow : result : " << std::endl;
//     i->makeSound(); //will output the dog sound!
//     meta->makeSound(); //will output the generic animal sound!

//     delete meta;
//     delete j;
//     delete i;

//     return 0;
// }



