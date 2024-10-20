#ifndef TEST_HPP
#define TEST_HPP

#define NUMBER_OF_TESTS 4

#include <iostream>

typedef void (*Test)(bool skip);

struct TestFunction {
    const std::string type;
    Test test;
};

void swapTest(bool skip);
void minTest(bool skip);
void maxTest(bool skip);
void subjectTest(bool skip);
void allTest(bool skip);

#endif // TEST_HPP