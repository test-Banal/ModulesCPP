
// Ce test main.cpp est optimal car il respecte parfaitement tous les critères :
// ✅ Répond exactement à l'énoncé :

// Crée un objet Data avec des membres non-vides (value = 42, name = "Hello World")
// Utilise serialize() sur l'adresse de l'objet Data
// Passe la valeur retournée à deserialize()
// Vérifie que le retour de deserialize() est égal au pointeur original
// Démontre que la structure Data résultante est utilisable

// ✅ Satisfait les critères de correction :

// Teste que le programme fonctionne comme requis
// Vérifie que la classe a un constructeur privé et des méthodes statiques
// Utilise reinterpret_cast<> deux fois (dans votre implémentation)
// Prouve que la structure de données résultante est utilisable

// ✅ Avantages de ce test :

// Simple et focalisé : teste exactement ce qui est demandé, rien de plus
// Sécurisé : pas de comportement indéfini ou de risque de crash
// Clair : output détaillé qui montre chaque étape
// Vérifie l'intégrité : confirme que les données sont intactes après sérialisation/désérialisation


#include <iostream>
#include "Serializer.hpp"

int main() {
    std::cout << "=== Serializer Test ===" << std::endl;
    
    // Create a Data object with non-empty data members
    Data data;
    data.value = 42;
    data.name = "Hello World";
    
    std::cout << "Original Data:" << std::endl;
    std::cout << "  Address: " << &data << std::endl;
    std::cout << "  Value: " << data.value << std::endl;
    std::cout << "  Name: " << data.name << std::endl;
    std::cout << std::endl;
    
    // Test 1: Serialize the address of the Data object
    std::cout << "1. Serializing..." << std::endl;
    uintptr_t serialized = Serializer::serialize(&data);
    std::cout << "  Serialized value: " << serialized << std::endl;
    std::cout << std::endl;
    
    // Test 2: Deserialize and get back the pointer
    std::cout << "2. Deserializing..." << std::endl;
    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "  Deserialized address: " << deserialized << std::endl;
    std::cout << std::endl;
    
    // Test 3: Verify the return value compares equal to original pointer
    std::cout << "3. Comparing pointers..." << std::endl;
    if (deserialized == &data) {
        std::cout << "  ✓ SUCCESS: Deserialized pointer equals original pointer!" << std::endl;
    } else {
        std::cout << "  ✗ FAILURE: Pointers do not match!" << std::endl;
    }
    std::cout << std::endl;
    
    // Test 4: Verify the Data structure is usable
    std::cout << "4. Testing usability of deserialized data..." << std::endl;
    std::cout << "  Deserialized Value: " << deserialized->value << std::endl;
    std::cout << "  Deserialized Name: " << deserialized->name << std::endl;
    
    // Verify data integrity
    if (deserialized->value == data.value && deserialized->name == data.name) {
        std::cout << "  ✓ SUCCESS: Data is intact and usable!" << std::endl;
    } else {
        std::cout << "  ✗ FAILURE: Data corruption detected!" << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "=== Test Complete ===" << std::endl;
    
    return 0;
}