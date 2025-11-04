/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneumann <aneumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:07:28 by aneumann          #+#    #+#             */
/*   Updated: 2025/11/04 15:07:01 by aneumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    
    Data data;
    data.value = 42;
    data.name = "Hello World";
    
    std::cout << "Data:" << std::endl;
    std::cout << "  Address: " << &data << std::endl;
    std::cout << "  Value: " << data.value << std::endl;
    std::cout << "  Name: " << data.name << std::endl;
    std::cout << std::endl;
    
    std::cout << "1. Serializing :" << std::endl;
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "  Serialized value: " << serialized << std::endl;
    std::cout << std::endl;
    
    std::cout << "2. Deserializing :" << std::endl;
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "  Deserialized address: " << deserialized << std::endl;
    std::cout << std::endl;
    
    std::cout << "3. Comparing pointers :" << std::endl;
    if (deserialized == &data) {
        std::cout << " SUCCESS: Deserialized pointer equals original pointer!" << std::endl;
    } else {
        std::cout << " FAILURE: Pointers don't match!" << std::endl;
    }
    std::cout << std::endl;
    
    std::cout << "4. Testing data :" << std::endl;
    std::cout << "  Deserialized Value: " << deserialized->value << std::endl;
    std::cout << "  Deserialized Name: " << deserialized->name << std::endl;
    
    if (deserialized->value == data.value && deserialized->name == data.name) {
        std::cout << " SUCCESS" << std::endl;
    } else {
        std::cout << " FAILURE" << std::endl;
    }
    
    std::cout << std::endl;    
    return 0;
}