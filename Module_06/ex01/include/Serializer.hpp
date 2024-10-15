#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <iomanip>
struct Data {
    std::string content;
};

class Serializer {
    public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);

    private:
    // Default constructor
    Serializer();

    // Copy Constructor
    Serializer(const Serializer &other);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Serializer &operator=(const Serializer &other);

    // Default Destructor
    ~Serializer();
};

#endif // SERIALIZER_HPP