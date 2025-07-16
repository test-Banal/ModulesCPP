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
Serializer(const Serializer &src);
~Serializer();
Serializer &operator=(const Serializer &rhs);

static uintptr_t serialize(Data *ptr);
static Data *deserialize(uintptr_t raw);
private :
Serializer();
};

#endif


// static void printData(const Data *data) {
//     if (data) {
//         std::cout << "Data ID: " << data->id << ", Name: " << data->name << std::endl;
//     } else {
//         std::cout << "Data is null." << std::endl;
//     }
// }