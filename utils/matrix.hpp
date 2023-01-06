#ifndef __MATRIX__
#define __MATRIX__

#include <iostream>
#include <string>

class Matrix_2x2 {
    public:
        Matrix_2x2(int a, int b, int c, int d); // The 4 values inside of the matrix
        int values[4];
        Matrix_2x2 inverse();
        // int * multiply(int vector[3]);
        int inverseDeterminant();
        std::string toString();
};

class Matrix_3x3 {
    public:
        Matrix_3x3(int a, int b, int c, int d, int e, int f, int g, int h, int i); // The 9 values inside of the matrix
        int values[9];
        Matrix_3x3 inverse();
        // int * multiply(int vector[3]);
        std::string toString();
        int inverseDeterminant();
};

#endif