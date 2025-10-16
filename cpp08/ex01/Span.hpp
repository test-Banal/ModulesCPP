#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <climits>

class Span {
public:
    //constructors
    Span();
    Span(unsigned int n );
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();
    
    //fonctions utilitr
    void addNumber(int num);
    int shortestSpan() const;
    int longestSpan() const;

    //template BONUS
    template <typename Input>
    void addRange(Input first, Input last) {
        long count = std::distance(first, last);
        if (count < 0)
            count = 0;
        if (_numbers.size() + static_cast<size_t>(count) > _maxSize)
            throw std::overflow_error("Not enough space");
        _numbers.insert(_numbers.end(), first, last);
    }

private:
    unsigned int _maxSize;
    std::vector<int> _numbers;
};

#endif


