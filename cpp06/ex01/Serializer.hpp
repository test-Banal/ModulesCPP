/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:08:05 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/04 15:05:33 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>
#include <cstring>
#include <iomanip>
#include <stdexcept>

struct Data {
    int value;
    std::string name;
};

class Serializer {
    public:
      static uintptr_t serialize(Data *ptr);
      static Data *deserialize(uintptr_t raw);

    private :
      Serializer();
       Serializer(const Serializer &src);
      ~Serializer();
      Serializer &operator=(const Serializer &rhs);
};

#endif