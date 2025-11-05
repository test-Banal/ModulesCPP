/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:46:28 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/05 14:57:54 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATERVER_HPP
#define WHATERVER_HPP

#include <cstring>

template <typename T>
const T& min(const T& a, const T& b) {
    return (b < a) ? b : a;
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