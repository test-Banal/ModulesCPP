#ifndef WHATERVER_HPP
#define WHATERVER_HPP

template <typename T>
const T& min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template <typename T>
const T& max(const T& a, const T& b) {
    return (a > b) ? a : b;
}       

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

#endif 