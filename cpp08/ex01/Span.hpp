#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
public:
    Span(unsigned int n);
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();

private:
    std::vector<int> numbers;
    unsigned int maxSize;
};

#endif
