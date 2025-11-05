/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:59:35 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/05 17:04:08 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}     

template <typename T>
Array<T>::Array(unsigned int n) : _size(n) {
    if (n == 0) {
        _data = NULL;
    } else {
        _data = new T[n](); //new + initialise = value-initialise = tip enonce , au lieu dune boucle 
    }
}   

template <typename T>
Array<T>::~Array() {
    delete[] _data;
}                       

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

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        Array tmp(other);   
        std::swap(_data, tmp._data);
        std::swap(_size, tmp._size);
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}       
#endif
