// #include <iostream>
// #include <ctime>
// #include <cstdlib>

// #include "Base.hpp"
// #include "A.hpp"
// #include "B.hpp"
// #include "C.hpp"
// #include "functions.hpp"

// Base* generate();
// void identify(Base* p);
// void identify(Base& p);

// int main() {
//     std::srand(std::time(0)); // init rand

//     Base* obj = generate();

//     std::cout << "Identify by pointer: ";
//     identify(obj);

//     std::cout << "Identify by reference: ";
//     identify(*obj);

//     delete obj;
//     return 0;
// }

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"

// Déclarations des fonctions
Base* generate();
void identify(Base* p);
void identify(Base& p);

int main() {
    std::cout << "=== CPP06 - Ex02: Real type identification ===" << std::endl;
    std::cout << std::endl;
    
    // Initialiser le générateur aléatoire
    std::srand(std::time(0));
    
    std::cout << "Testing multiple random generations..." << std::endl;
    std::cout << std::endl;
    
    // Test avec plusieurs objets pour voir la randomisation
    for (int i = 0; i < 5; i++) {
        std::cout << "--- Test " << (i + 1) << " ---" << std::endl;
        
        Base* obj = generate();
        
        std::cout << "Identify by pointer:   ";
        identify(obj);
        
        std::cout << "Identify by reference: ";
        identify(*obj);
        
        delete obj;
        std::cout << std::endl;
    }
    
    std::cout << "=== Testing edge cases ===" << std::endl;
    std::cout << std::endl;
    
    // Test avec pointeur NULL (optionnel, pour robustesse)
    std::cout << "Testing NULL pointer:" << std::endl;
    std::cout << "Identify NULL pointer: ";
    identify(static_cast<Base*>(NULL));
    
    std::cout << std::endl;
    std::cout << "=== All tests completed ===" << std::endl;
    
    return 0;
}