#include <iostream>
#include "Span.hpp"

int main() 
{

        
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;


return 0;

//try {

// int arr[] = {100, 101, 150, -10};
//         Span sp2(10);
//         sp2.addRange(arr, arr + (sizeof(arr)/sizeof(arr[0])));
//         std::cout << sp2.shortestSpan() << "\n"; // 1
//         std::cout << sp2.longestSpan()  << "\n"; // 160

//     } catch (const std::exception& e) {
//         std::cout << "Error: " << e.what() << '\n';
//     }
}