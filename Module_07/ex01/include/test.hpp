#ifndef TEST_HPP
#define TEST_HPP

#define NUMBER_OF_TESTS 4

#include "../include/colors.hpp"
#include "../include/display.hpp"
#include "../include/iter.hpp"
#include <iostream>

typedef void (*Test)(bool skip);

struct TestFunction {
    const std::string type;
    Test test;
};

void incrementByHundred(int &value);
void randomize(int &value);
void uppercase(std::string &str);
void lowercase(std::string &str);
void doubleValue(double &value);

void testInt(bool skip);
void testDouble(bool skip);
void testString(bool skip);
void allTest(bool skip);

#endif // TEST_HPP