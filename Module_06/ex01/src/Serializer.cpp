#include "../include/Serializer.hpp"
#include "../include/colors.hpp"
#include <cstdint>

Serializer::Serializer() {
    std::cout << YELLOW << "🛠️ Default Serializer Constructor called 🛠️" << RESET << std::endl;
}

Serializer::~Serializer() {
    std::cout << RED << "🧨 Serializer Destructor called 🧨" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &other) {
    (void)other;
    std::cout << YELLOW << "🖨️ Serializer Copy Constructor called 🖨️" << RESET << std::endl;
}

Serializer &Serializer::operator=(const Serializer &other) {
    // Check for self-assignment
    if (this != &other) {
    }
    std::cout << YELLOW << "📞 Serializer Copy Assignment Operator called 📞" << RESET << std::endl;
    return *this;
}

uintptr_t Serializer::serialize(Data *ptr) {
    uintptr_t newPtr = reinterpret_cast<uintptr_t>(ptr);
    std::cout << BOLD_ITALIC_PINK << "Serialized address: " << newPtr << RESET << std::endl;
    return newPtr;
}

Data *Serializer::deserialize(uintptr_t raw) {
    Data *ptr = reinterpret_cast<Data *>(raw);
    std::cout << BOLD_ITALIC_YELLOW << "Deserialized address: " << ptr << RESET << std::endl;
    return ptr;
}