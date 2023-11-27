#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Arduino.h>

int linearFunction(int* time, int counts, double* centimetres);
int thirdDegreePolynomialFunction(int* time, int counts, double* centimetres);
int powerFunction(int* time, int counts, double* centimetres);

#endif