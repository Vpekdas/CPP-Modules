#include "../include/Serializer.hpp"
#include "../include/colors.hpp"

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

unsigned long Serializer::serialize(Data *ptr) {
    return reinterpret_cast<unsigned long>(ptr);
}

Data *Serializer::deserialize(unsigned long raw) {
    return reinterpret_cast<Data *>(raw);
}