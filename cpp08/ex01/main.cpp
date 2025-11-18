#include <iostream>
#include "Span.hpp"

#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()

int main() {
    // Initialiser le générateur aléatoire
    std::srand(static_cast<unsigned int>(std::time(0)));
    
    try {
        // Générer un nombre aléatoire entre 5 et 20
        int randomCount = (std::rand() % 16) + 5;  // rand() % 16 donne [0,15], +5 donne [5,20]
        
        std::cout << "Testing with " << randomCount << " random numbers\n";
        
        // Créer un Span avec ce nombre d'éléments
        Span sp(randomCount);
        
        // Créer un vecteur avec des nombres aléatoires
        std::vector<int> numbers;
        for (int i = 0; i < randomCount; ++i) {
            int randomNum = std::rand() % 1000;  // Nombres entre 0 et 999
            numbers.push_back(randomNum);
            std::cout << randomNum << " ";
        }
        std::cout << "\n\n";
        
        // Ajouter tous les nombres via addRange
        sp.addRange(numbers.begin(), numbers.end());
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << '\n';
    }
    
    return 0;
}

// int main() 
// {

        
// Span sp = Span(5);
// sp.addNumber(6);
// sp.addNumber(3);
// sp.addNumber(17);
// sp.addNumber(9);
// sp.addNumber(11);
// std::cout << sp.shortestSpan() << std::endl;
// std::cout << sp.longestSpan() << std::endl;


// return 0;

// //try {

// // int arr[] = {100, 101, 150, -10};
// //         Span sp2(10);
// //         sp2.addRange(arr, arr + (sizeof(arr)/sizeof(arr[0])));
// //         std::cout << sp2.shortestSpan() << "\n"; // 1
// //         std::cout << sp2.longestSpan()  << "\n"; // 160

// //     } catch (const std::exception& e) {
// //         std::cout << "Error: " << e.what() << '\n';
// //     }
// }


//         sp2.addRange(arr, arr + (sizeof(arr)/sizeof(arr[0])));
// sizeof(arr) = taille tot du tableau en bytes : 16bytes  car 4 elements
// sizeof(arr[0]) = taille d'un seul element en bytes
// sizeof(arr)/sizeof(arr[0]) = nombre total d'element
// arr -> pointe sur le premier element
// sizeof(arr)/sizeof(arr[0])-> pointe sur le dernier element