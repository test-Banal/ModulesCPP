/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:46:45 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/03 16:21:48 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* const array, const size_t length, void (*func)(const T&)) { 
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

//option 1
template <typename T>
void iter(T* array,const size_t length, void (*func)( T&)) { 
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}

// alternative : option :2
// template<typename T, typename F>
// void    iter(T *array, const size_t len, F f)
// {
//     if (!array)
//         return ;
//     for (size_t i = 0; i < len; i++)
//         f(array[i]);
// }

template <typename T>
void printElement(const T& element) {
    std::cout << element << std::endl;
}

#endif
