#include <iostream>
#include <stack>
#include <deque>
#include <list>
#include "MutantStack.hpp"


int main()
{
MutantStack<int>
mstack;
mstack.push(5);
mstack.push(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
//[...]
mstack.push(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}



// // 1) Test du sujet avec MutantStack
// void subjectTestMutant() {
//     std::cout << "=== Subject test with MutantStack ===" << std::endl;

//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;   // doit afficher 17
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;  // doit afficher 1
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     // [...]
//     mstack.push(0);

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     ++it;
//     --it;

//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     // Test de compatibilité avec std::stack
//     std::stack<int> s(mstack);
// }

// // 2) Même test, mais avec std::list (comme dit dans le sujet)
// void subjectTestList() {
//     std::cout << "=== Subject-like test with std::list ===" << std::endl;

//     std::list<int> lst;
//     lst.push_back(5);
//     lst.push_back(17);
//     std::cout << lst.back() << std::endl;   // équivalent de top() -> back()
//     lst.pop_back();                         // équivalent de pop()
//     std::cout << lst.size() << std::endl;
//     lst.push_back(3);
//     lst.push_back(5);
//     lst.push_back(737);
//     // [...]
//     lst.push_back(0);

//     std::list<int>::iterator it = lst.begin();
//     std::list<int>::iterator ite = lst.end();

//     ++it;
//     --it;

//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     // Ici pas besoin de std::stack, mais on peut copier la liste si on veut
//     std::list<int> copy(lst);
// }

// // 3) Test des itérateurs (non-const + const + cas vide)
// void iteratorTest() {
//     std::cout << "=== Iterator tests ===" << std::endl;

//     MutantStack<int> mstack;
//     for (int i = 1; i <= 10; ++i)
//         mstack.push(i);

//     std::cout << "Forward (const_iterator): ";
//     const MutantStack<int> &cm = mstack;
//     for (MutantStack<int>::const_iterator it = cm.begin(); it != cm.end(); ++it)
//         std::cout << *it << ' ';
//     std::cout << std::endl;

//     std::cout << "Empty iteration (should print nothing): ";
//     MutantStack<int> empty;
//     for (MutantStack<int>::iterator it = empty.begin(); it != empty.end(); ++it)
//         std::cout << *it << ' ';
//     std::cout << std::endl;
// }

// // 4) Test du constructeur de copie et de l'opérateur d'affectation
// void copyAssignTest() {
//     std::cout << "=== Copy & Assignment tests ===" << std::endl;

//     MutantStack<char> ms1;
//     for (char c = 'a'; c <= 'e'; ++c)
//         ms1.push(c);

//     MutantStack<char> ms2(ms1); // copy constructor
//     std::cout << "Copy-constructor output: ";
//     for (MutantStack<char>::iterator it = ms2.begin(); it != ms2.end(); ++it)
//         std::cout << *it << ' ';
//     std::cout << std::endl;

//     MutantStack<char> ms3;
//     ms3 = ms1; // assignment operator
//     std::cout << "Assignment output:       ";
//     for (MutantStack<char>::iterator it = ms3.begin(); it != ms3.end(); ++it)
//         std::cout << *it << ' ';
//     std::cout << std::endl;
// }

// int main() {
//     subjectTestMutant(); // main du sujet, version MutantStack
//     subjectTestList();   // même chose avec std::list (comme demandé)
//     iteratorTest();      // tests d'itérateurs et const_iterator
//     copyAssignTest();    // tests de copie / affectation
//     return 0;
// }
