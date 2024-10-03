#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal {
    public:
    Animal();
    Animal(const std::string &name);

    // Copy assignment operator: Ensures that the current object gets the same state as the other
    // object. This is necessary to correctly manage the internal state and avoid issues with
    // resource management.
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);

    // Virtual destructor to ensure derived class destructors are called,
    // preventing resource leaks when deleting objects through base class pointers.
    virtual ~Animal();

    void setName(const std::string &name);
    void setType(const std::string &type);
    const std::string &getName() const;
    const std::string &getType() const;

    // Each derived class must be able to provide its own implementation of makeSound.
    // This is why the method is declared virtual.
    // Abstract class, so we cannot create an instance of Animal.
    virtual void makeSound() const = 0;

    protected:
    std::string _type;
    std::string _name;
};

#endif // ANIMAL_HPP