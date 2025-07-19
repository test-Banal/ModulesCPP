#include <iostream>
#include "iter.hpp"


int main() {
    int array[] = {1, 2, 3, 4, 5};
    ::iter(array, 2, printElement);

    std::cout << "-----\n" << std::endl;
    std::string strArray[] = {"hello", "world", "42"};
    ::iter(strArray, 3, printElement);

    return 0;
}
