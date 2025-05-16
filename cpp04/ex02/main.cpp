#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
 
// int main()
// {
//     std::cout << "========== Test des classes avec Brain ==========\n" << std::endl;
    
//     // Test des constructeurs
//     std::cout << "--- Création des objets ---" << std::endl;
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
    
//     // Test de makeSound
//     std::cout << "\n--- Test makeSound() ---" << std::endl;
//     std::cout << "Sound de j (Dog): ";
//     j->makeSound();
//     std::cout << "Sound de i (Cat): ";
//     i->makeSound();
    
//     // Test des destructeurs qui doivent delete le Brain
//     std::cout << "\n--- Destruction des objets ---" << std::endl;
//     delete j; // ne devrait pas créer de fuites
//     delete i; // ne devrait pas créer de fuites
    
//     std::cout << "\n========== Test de création et destruction du tableau d'Animals ==========\n" << std::endl;
    
//     const int animalCount = 10;
//     Animal* animals[animalCount];
    
//     std::cout << "--- Création du tableau d'animaux ---" << std::endl;
//     // Remplir la première moitié avec des Dogs
//     for (int k = 0; k < animalCount / 2; k++) {
//         std::cout << "Création de Dog #" << k << std::endl;
//         animals[k] = new Dog();
//     }
    
//     // Remplir la seconde moitié avec des Cats
//     for (int k = animalCount / 2; k < animalCount; k++) {
//         std::cout << "Création de Cat #" << k << std::endl;
//         animals[k] = new Cat();
//     }
    
//     // Tester les sons de quelques animaux du tableau
//     std::cout << "\n--- Test de quelques animaux du tableau ---" << std::endl;
//     std::cout << "Sound de animals[0] (Dog): ";
//     animals[0]->makeSound();
//     std::cout << "Sound de animals[" << animalCount/2 << "] (Cat): ";
//     animals[animalCount/2]->makeSound();
    
//     // Delete tous les animaux du tableau
//     std::cout << "\n--- Destruction du tableau d'animaux ---" << std::endl;
//     for (int k = 0; k < animalCount; k++) {
//         std::cout << "Destruction de animal #" << k << std::endl;
//         delete animals[k];
//     }
    
//     std::cout << "\n========== Test de copie profonde ==========\n" << std::endl;
    
//     // Test de copie profonde pour Dog
//     std::cout << "--- Test de copie profonde pour Dog ---" << std::endl;
//     Dog* originalDog = new Dog();
    
//     // Modification du Brain pour tester si la copie est profonde
//     // Puisque Brain est privé, nous devrons ajouter des fonctions pour le tester
//     // Par exemple, nous pourrions implémenter des getters/setters pour accéder aux idées
//     std::cout << "Ajout d'idées au cerveau du chien original" << std::endl;
    
//     // Ici on suppose que Dog a des méthodes pour manipuler son Brain
//     // Ces méthodes devraient être implémentées dans les classes Dog/Cat
//     Dog dogCopy(*originalDog); // Constructeur de copie
    
//     std::cout << "Original dog address: " << originalDog << std::endl;
//     std::cout << "Copy dog address: " << &dogCopy << std::endl;
    
//     // Test avec l'opérateur d'affectation
//     std::cout << "\n--- Test de l'opérateur d'affectation pour Dog ---" << std::endl;
//     Dog anotherDog;
//     anotherDog = *originalDog;
    
//     std::cout << "Original dog address: " << originalDog << std::endl;
//     std::cout << "Assigned dog address: " << &anotherDog << std::endl;
    
//     // Test de copie profonde pour Cat
//     std::cout << "\n--- Test de copie profonde pour Cat ---" << std::endl;
//     Cat* originalCat = new Cat();
    
//     std::cout << "Ajout d'idées au cerveau du chat original" << std::endl;
    
//     Cat catCopy(*originalCat); // Constructeur de copie
    
//     std::cout << "Original cat address: " << originalCat << std::endl;
//     std::cout << "Copy cat address: " << &catCopy << std::endl;
    
//     // Test avec l'opérateur d'affectation
//     std::cout << "\n--- Test de l'opérateur d'affectation pour Cat ---" << std::endl;
//     Cat anotherCat;
//     anotherCat = *originalCat;
    
//     std::cout << "Original cat address: " << originalCat << std::endl;
//     std::cout << "Assigned cat address: " << &anotherCat << std::endl;
    
//     // Suppression des objets créés sur le tas
//     delete originalDog;
//     delete originalCat;
    
//     std::cout << "\n--- Fin du programme ---" << std::endl;
    
//     return 0;
// }


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
