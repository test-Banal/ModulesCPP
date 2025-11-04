/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:07:39 by aneumann          #+#    #+#             */
/*   Updated: 2025/10/27 19:07:41 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }

Data* Serializer::deserialize(uintptr_t raw) {
        return reinterpret_cast<Data *>(raw);
    }

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &src) {
    (void)src;
}

Serializer::~Serializer() {}

Serializer &Serializer::operator=(const Serializer &rhs) {
    if (this != &rhs) {
    }
    return *this;
}
