#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>
#include <iterator>   // std::distance
#include "easyfind.hpp"

int main() {
int arr[] = {1, 2, 3, 4, 5};
std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));


    try {
        std::vector<int>::const_iterator it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        easyfind(vec, 10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}


// template <typename C>
// void printContainer(const C &c, const char* name) {
//     std::cout << name << " = [";
//     typename C::const_iterator it = c.begin();
//     while (it != c.end()) {
//         std::cout << *it;
//         ++it;
//         if (it != c.end()) std::cout << ", ";
//     }
//     std::cout << "]\n";
// }

// template <typename C>
// void expectFound(C &c, int needle, long expectedIndex, const char* label) {
//     std::cout << "[FOUND] " << label << " : chercher " << needle << " ... ";
//     try {
//         typename C::iterator it = easyfind(c, needle);
//         long idx = std::distance(c.begin(), it);
//         if (it == c.end()) {
//             std::cout << "ECHEC (retour end())\n";
//         } else if (*it != needle) {
//             std::cout << "ECHEC (valeur trouvée=" << *it << ")\n";
//         } else if (expectedIndex >= 0 && idx != expectedIndex) {
//             std::cout << "ECHEC (index=" << idx << ", attendu " << expectedIndex << ")\n";
//         } else {
//             std::cout << "OK (index=" << idx << ")\n";
//         }
//     } catch (const std::exception &e) {
//         std::cout << "ECHEC (exception: " << e.what() << ")\n";
//     }
// }

// template <typename C>
// void expectNotFound(C &c, int needle, const char* label) {
//     std::cout << "[NOT FOUND] " << label << " : chercher " << needle << " ... ";
//     try {
//         typename C::iterator it = easyfind(c, needle);
//         if (it == c.end()) {
//             std::cout << "OK (end())\n";
//         } else {
//             std::cout << "ECHEC (a trouvé " << *it << ")\n";
//         }
//     } catch (const std::exception &e) {
//         // Si easyfind lève une exception quand non trouvé, c'est OK aussi.
//         std::cout << "OK (exception: " << e.what() << ")\n";
//     }
// }

// int main() {
//     std::cout << "===== Tests easyfind (ex00) =====\n\n";

//     // 1) std::vector<int> — cas de base + doublons + absent
//     {
//         std::vector<int> v;
//         v.push_back(1); v.push_back(3); v.push_back(3); v.push_back(7); v.push_back(9);
//         printContainer(v, "vector v");

//         // première occurrence de 3 doit être à l'index 1
//         expectFound(v, 3, 1, "vector v / doublons -> premiere occurrence");
//         // valeur présente en fin
//         expectFound(v, 9, 4, "vector v / present en fin");
//         // valeur absente
//         expectNotFound(v, 2, "vector v / absent");
//     }

//     std::cout << "\n";

//     // 2) std::list<int> — début / milieu / absent
//     {
//         std::list<int> lst;
//         lst.push_back(10); lst.push_back(20); lst.push_back(30); lst.push_back(40);
//         printContainer(lst, "list lst");

//         // trouvé au début
//         expectFound(lst, 10, 0, "list lst / debut");
//         // trouvé au milieu
//         expectFound(lst, 30, 2, "list lst / milieu");
//         // absent
//         expectNotFound(lst, 99, "list lst / absent");
//     }

//     std::cout << "\n";

//     // 3) std::deque<int> — plage plus large
//     {
//         std::deque<int> dq;
//         for (int i = 100; i < 200; ++i) dq.push_back(i);
//         printContainer(dq, "deque dq (100..199)");

//         expectFound(dq, 150, 50, "deque dq / milieu (150)");
//         expectFound(dq, 100, 0, "deque dq / debut (100)");
//         expectFound(dq, 199, 99, "deque dq / fin (199)");
//         expectNotFound(dq, 42, "deque dq / absent (42)");
//     }

//     std::cout << "\n";

//     // 4) Conteneur vide
//     {
//         std::vector<int> empty;
//         printContainer(empty, "vector empty");
//         expectNotFound(empty, 1, "vector empty / recherche dans vide");
//     }

//     std::cout << "\n";

//     // 5) Valeurs négatives + zéro
//     {
//         std::vector<int> neg;
//         neg.push_back(-5); neg.push_back(-1); neg.push_back(0); neg.push_back(2);
//         printContainer(neg, "vector neg");

//         expectFound(neg, -1, 1, "vector neg / negatif");
//         expectFound(neg, 0, 2, "vector neg / zero");
//         expectNotFound(neg, -7, "vector neg / absent negatif");
//     }

//     std::cout << "\n";

//     // 6) “Taille large” (sanity/perf basique) : recherche en fin
//     {
//         std::vector<int> large;
//         large.reserve(10000);
//         for (int i = 0; i < 10000; ++i) large.push_back(i);
//         std::cout << "vector large = [0..9999]\n";
//         expectFound(large, 9999, 9999, "vector large / dernier element");
//         expectNotFound(large, 10001, "vector large / absent");
//     }

//     std::cout << "\n===== Fin des tests =====\n";
//     return 0;
// }
