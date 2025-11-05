/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:59:44 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/05 17:02:27 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>


template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    ~Array();

    Array& operator=(const Array& other);
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;

private:
    T* _data;
    unsigned int _size;
};

#include "Array.tpp"

#endif
