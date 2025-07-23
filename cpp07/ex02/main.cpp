#include "Array.hpp"

int main() {

    //     std::cout << "=== Test allocation new int() ===" << std::endl;
    // int* test = new int();
    // std::cout << "*test = " << *test << std::endl;
    // delete test;
    
    std::cout << "=== Test du constructeur vide ===" << std::endl;
Array<int> empty;
std::cout << "empty.size() = " << empty.size() << std::endl;

try {
    std::cout << "Accessing element 0 in empty array: ";
    std::cout << empty[0] << std::endl; // Doit throw
} catch (std::exception &e) {
    std::cerr << "Caught exception: " << e.what() << std::endl;
}

    std::cout << "=== Test du constructeur vide ===" << std::endl;


    try {

        Array<int> a(5);
        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 2;

        std::cout << "Array a: ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        Array<int> b = a;
        b[0] = 99;

        std::cout << "Array a after modifying b: ";
        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;

        std::cout << "Array b: ";
        for (unsigned int i = 0; i < b.size(); i++)
            std::cout << b[i] << " ";
        std::cout << std::endl;

        std::cout << "Accessing out of bounds..." << std::endl;
        std::cout << a[42] << std::endl; // Doit throw

    } catch (std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
