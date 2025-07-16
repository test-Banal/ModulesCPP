#include <iostream>
#include "Serializer.hpp"

// int main() {
//     Data data = {42, "Example"};
    
//     // Serialize the data
//     uintptr_t raw = Serializer::serialize(&data);
    
//     // Deserialize the data
//     Data *deserializedData = Serializer::deserialize(raw);
    
//     // Print the deserialized data
//     if (deserializedData) {
//         std::cout << "Deserialized Data ID: " << deserializedData->id 
//                   << ", Name: " << deserializedData->name << std::endl;
//     } else {
//         std::cout << "Deserialization failed." << std::endl;
//     }
    
//     return 0;
// }   


// int main() {
//     Data data;
//     data.value = 42;
//     data.name = "Alban";

//     std::cout << "Original pointer: " << &data << std::endl;

//     uintptr_t raw = Serializer::serialize(&data);
//     Data* recovered = Serializer::deserialize(raw);

//     std::cout << "Recovered pointer: " << recovered << std::endl;
//     std::cout << "Value: " << recovered->value << ", Name: " << recovered->name << std::endl;

//     if (recovered == &data)
//         std::cout << "Success: deserialized pointer matches original!" << std::endl;
//     else
//         std::cout << "Failure: deserialized pointer does not match original!" << std::endl;

//     return 0;
// }

#include <iostream>
#include "Serializer.hpp"

int main() {
    std::cout << "=== Test 1: serialize & deserialize same pointer ===" << std::endl;

    Data data;
    data.value = 1337;
    data.name = "Alban";

    uintptr_t raw = Serializer::serialize(&data);
    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Original pointer:   " << &data << std::endl;
    std::cout << "Serialized raw int: " << raw << std::endl;
    std::cout << "Recovered pointer:  " << recovered << std::endl;
    std::cout << "Recovered values:   " << recovered->value << ", " << recovered->name << std::endl;

    if (recovered == &data)
        std::cout << "[✔] Pointers match\n" << std::endl;
    else
        std::cout << "[✘] Pointers do not match\n" << std::endl;


    std::cout << "=== Test 2: deserialize a known address ===" << std::endl;
    uintptr_t fake_raw = reinterpret_cast<uintptr_t>(&data); // adresse connue
    Data* test_ptr = Serializer::deserialize(fake_raw);
    std::cout << "Deserialized known address: " << test_ptr << std::endl;
    std::cout << "Value: " << test_ptr->value << ", Name: " << test_ptr->name << "\n" << std::endl;


    std::cout << "=== Test 3: deserialize a random uintptr_t ===" << std::endl;
    uintptr_t trap = 0x1234; // adresse très probablement invalide
    Data* trap_ptr = Serializer::deserialize(trap);

    std::cout << "Trying to access deserialized pointer from 0x1234..." << std::endl;

    // ATTENTION ⚠️ Ceci est dangereux — on le protège
    try {
        std::cout << "Trap pointer: " << trap_ptr << std::endl;
        std::cout << "Accessing trap_ptr->value (UNDEFINED BEHAVIOR):" << std::endl;
        std::cout << "Value: " << trap_ptr->value << std::endl; // 💥 peut crasher ici
        std::cout << "[?] Somehow survived!\n" << std::endl;
    } catch (...) {
        std::cout << "[✘] Crashed or failed safely\n" << std::endl;
    }

    return 0;
}
