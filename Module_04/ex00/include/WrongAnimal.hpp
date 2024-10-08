#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {
    public:
    WrongAnimal();
    WrongAnimal(const std::string &name);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &other);

    // Virtual destructor to ensure derived class destructors are called,
    // preventing resource leaks when deleting objects through base class pointers.
    virtual ~WrongAnimal();

    void setName(const std::string &name);
    void setType(const std::string &type);
    const std::string &getName() const;
    const std::string &getType() const;

    void makeSound() const;

    protected:
    std::string _type;
    std::string _name;
};

#endif // ANIMAL_HPP