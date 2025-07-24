#include "Span.hpp"

#include <limits>
Span::Span(unsigned int n) : maxSize(n) {}

void Span::addNumber(int num) {
    if (numbers.size() >= maxSize) {
        throw std::length_error("Span is full");
    }
    numbers.push_back(num);
}

int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    auto minMax = std::minmax_element(numbers.begin(), numbers.end());
    return *minMax.second - *minMax.first;
}

