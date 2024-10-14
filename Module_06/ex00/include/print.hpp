#ifndef PRINT_HPP
#define PRINT_HPP

#include "../include/ScalarConverter.hpp"

void printDisplayableChar(Convertible *convertible);
void printDisplayableInt(Convertible *convertible);
void printDisplayableFloat(Convertible *convertible);
void printDisplayableDouble(Convertible *convertible);

void printDisplayable(Convertible *convertible);
void printNonDisplayable(Convertible *convertible);
void printImpossible(Convertible *convertible);

#endif