#include "functions.h"

int linearFunction(int* time, int counts, double* centimetres) {
    if (time != NULL && centimetres != NULL) {
        int beginTime = micros();
        *centimetres = -0.0401*(double)counts + 30.795;
        *time = micros() - beginTime;
        return 0;
    }
    return -1;
}

int thirdDegreePolynomialFunction(int* time, int counts, double* centimetres) {
    if (time != NULL && centimetres != NULL) {
        int beginTime = micros();
        *centimetres = -3*pow(10,-7)*pow((double)counts, 3) + 0.0005*pow((double)counts, 2) - 0.2905*(double)counts + 66.391;
        *time = micros() - beginTime;
        return 0;
    }
    return -1;
}

int powerFunction(int* time, int counts, double* centimetres) {
    if (time != NULL && centimetres != NULL) {
        int beginTime = micros();
        *centimetres = 17136*pow((double)counts,-1.214);
        *time = micros() - beginTime;
        return 0;
    }
    return -1;
}