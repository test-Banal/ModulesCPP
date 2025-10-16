#include "Span.hpp"

Span::Span() : _maxSize(0), _numbers() {}

Span::Span(unsigned int n) : _maxSize(n), _numbers() {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span &other) {
    if ( this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (_numbers.size() >= _maxSize)
        throw std::overflow_error("Span is full");
    _numbers.push_back(num);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::logic_error("Not enough elements");
    
    std::vector<int> tmp(_numbers);
    std::sort(tmp.begin(), tmp.end());

    int best = INT_MAX;
    for (size_t i = 1; i < tmp.size(); ++i) {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < best)
            best = diff;
        if (best == 0)
            break;
    }
    return best;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw std::logic_error("Not enough elements");
    }
        std::vector<int>::const_iterator itMin = std::min_element(_numbers.begin(), _numbers.end());
        std::vector<int>::const_iterator itMax = std::max_element(_numbers.begin(), _numbers.end());
        return *itMax - *itMin;
}