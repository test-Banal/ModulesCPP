#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
int arr[] = {1, 2, 3, 4, 5};
std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));


    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
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
