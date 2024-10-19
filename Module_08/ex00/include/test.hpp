#ifndef TEST_HPP
#define TEST_HPP

#include <iostream>

#define NUMBER_OF_TESTS 3

typedef void(*Test)(bool skip);

struct TestFunction {
    const std::string type;
    Test test;
};

void testVector(bool skip);
void testList(bool skip);
void testAll(bool skip);

#endif // TEST_HPP