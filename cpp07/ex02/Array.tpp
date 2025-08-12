#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

//constructeur par defaut
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}     

//constructeur avec taille, allocation et intialisation
template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    if (n == 0) {
        _data = NULL;
    } else {
        _data = new T[n];
        for (unsigned int i = 0; i < n; ++i) {
            _data[i] = T(); // initialise avec des valeurs par defaut
        }
    }
}   

//constructeur de copie
template <typename T>
Array<T>::Array(const Array& other) : _size(other._size) {
    if (_size == 0) {
        _data = NULL;
    } else {
        _data = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }
}   

//destructeur + libere la memoire
template <typename T>
Array<T>::~Array() {
    delete[] _data;
}                       

//operateur d'affectation, libere ancienn contenu/memoire et copie le nouveau
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        if (_size == 0) {
            _data = NULL;
        } else {
            _data = new T[_size];
            for (unsigned int i = 0; i < _size; ++i) {
                _data[i] = other._data[i];
            }
        }
    }
    return *this;
}

//operateur d'acces : ecriture et lecture
template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

//operateur d'acces : lecture 
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

// retourne la taille du tableau
template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}       
#endif // ARRAY_TPP