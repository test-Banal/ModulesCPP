#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
 
void testAnimalBasics() {
    std::cout << "========== Test des classes avec Brain ==========\n\n";

    std::cout << "--- Création des objets ---\n";
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\n--- Test makeSound() ---\n";
    std::cout << "Sound de j (Dog): ";
    j->makeSound();
    std::cout << "Sound de i (Cat): ";
    i->makeSound();

    std::cout << "\n--- Destruction des objets ---\n";
    delete j;
    delete i;
}

void testAnimalArray() {
    std::cout << "\n========== Test de création et destruction du tableau d'Animals ==========\n\n";

    const int size = 10;
    Animal* animals[size];

    std::cout << "--- Création du tableau d'animaux ---\n";
    for (int i = 0; i < size; ++i) {
        if (i < size / 2) {
            std::cout << "Création de Dog #" << i << std::endl;
            animals[i] = new Dog();
        } else {
            std::cout << "Création de Cat #" << i << std::endl;
            animals[i] = new Cat();
        }
    }

    std::cout << "\n--- Test de quelques animaux du tableau ---\n";
    std::cout << "Sound de animals[0] (Dog): ";
    animals[0]->makeSound();
    std::cout << "Sound de animals[5] (Cat): ";
    animals[5]->makeSound();

    std::cout << "\n--- Destruction du tableau d'animaux ---\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "Destruction de animal #" << i << std::endl;
        delete animals[i];
    }
}

void testDeepCopy() {
    std::cout << "\n========== Test de copie profonde ==========\n";

    std::cout << "\n--- Test de copie profonde pour Dog ---\n";
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Je veux manger.");
    originalDog.getBrain()->setIdea(1, "Je veux courir.");

    Dog copyDog(originalDog); // constructeur de copie

    std::cout << "OriginalDog Brain[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "CopyDog Brain[0]: " << copyDog.getBrain()->getIdea(0) << std::endl;

    originalDog.getBrain()->setIdea(0, "Je veux dormir.");
    std::cout << "Après modification de l'original :\n";
    std::cout << "OriginalDog Brain[0]: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "CopyDog Brain[0] (inchangé) : " << copyDog.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Test de l'opérateur d'affectation pour Dog ---\n";
    Dog assignedDog;
    assignedDog = originalDog;

    std::cout << "OriginalDog Brain[1]: " << originalDog.getBrain()->getIdea(1) << std::endl;
    std::cout << "AssignedDog Brain[1]: " << assignedDog.getBrain()->getIdea(1) << std::endl;

    std::cout << "\n--- Test de copie profonde pour Cat ---\n";
    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "Je veux chasser.");
    originalCat.getBrain()->setIdea(1, "Je veux dormir au soleil.");

    Cat copyCat(originalCat);

    std::cout << "OriginalCat Brain[0]: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "CopyCat Brain[0]: " << copyCat.getBrain()->getIdea(0) << std::endl;

    originalCat.getBrain()->setIdea(0, "Je veux griffer.");
    std::cout << "Après modification de l'original :\n";
    std::cout << "OriginalCat Brain[0]: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "CopyCat Brain[0] (inchangé) : " << copyCat.getBrain()->getIdea(0) << std::endl;

    std::cout << "\n--- Test de l'opérateur d'affectation pour Cat ---\n";
    Cat assignedCat;
    assignedCat = originalCat;

    std::cout << "OriginalCat Brain[1]: " << originalCat.getBrain()->getIdea(1) << std::endl;
    std::cout << "AssignedCat Brain[1]: " << assignedCat.getBrain()->getIdea(1) << std::endl;
}

int main() {
    testAnimalBasics();
    testAnimalArray();
    testDeepCopy();

    std::cout << "\n--- Fin du programme ---" << std::endl;
    return 0;
}
