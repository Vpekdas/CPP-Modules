#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>

struct Data {
    std::string name;
};

class Serializer {
    public:
    static unsigned long serialize(Data *ptr);
    static Data *deserialize(unsigned long raw);

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