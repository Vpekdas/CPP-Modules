#include "../include/Serializer.hpp"
#include "../include/colors.hpp"

int main() {

    // TODO: Improve the main. (more test, cool emoji and colors.)
    Data data;
    data.name = "Too too roo !";

    unsigned long serial;

    serial = Serializer::serialize(&data);
    std::cout << CYAN << "serialized: " << serial << RESET << std::endl;

    Data *newData = Serializer::deserialize(serial);
    std::cout << CYAN << "deserialized: " << newData << RESET << std::endl;
    std::cout << CYAN << "original address: " << &data << RESET << std::endl;
}