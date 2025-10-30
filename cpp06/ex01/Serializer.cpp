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