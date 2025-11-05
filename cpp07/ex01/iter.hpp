/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:46:45 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/05 15:53:28 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstddef>

template<typename T, typename F>
void    iter(T *array, const size_t len, F f)
{
        if (!array)
            return ;
        for (size_t i = 0; i < len; i++)
            f(array[i]);
    }



template<typename T, typename F>
void    iter(const T *array, const size_t len, F f)
{
        if (!array)
            return ;
        for (size_t i = 0; i < len; i++)
            f(array[i]);
    }

template <typename T>
void printElement(const T& element) {
    std::cout << element << std::endl;
}

template <typename T>
void increment(T& x) { ++x; }

#endif



// alternative : option :2
//cas ou on accepte que des fonctions mais pas de pointeurs de fonctions => pour cela faire avec un template !

// template <typename T>
// void iter(T* const array, const size_t length, void (*func)(const T&)) { 
//     for (size_t i = 0; i < length; ++i) {
//         func(array[i]);
//     }
// }
    
// template <typename T>
// void iter(T* array,const size_t length, void (*func)( T&)) { 
//     for (size_t i = 0; i < length; ++i) {
//         func(array[i]);
//     }
// }


// a mettre dans le main : 

// int array[] = {1, 2, 3, 4, 5};
// ::iter(array, 2, &printElement<int>);
// ::iter(array, 5, &increment<int>);

// std::cout << "-----\n" << std::endl;
// std::string strArray[] = {"hello", "world", "42"};
// ::iter(strArray, 3, &printElement<std::string>);

    