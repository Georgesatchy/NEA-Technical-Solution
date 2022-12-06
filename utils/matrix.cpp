#include "matrix.hpp"

Matrix_2x2::Matrix_2x2(int a, int b, int c, int d) {
    values[0] = a;
    values[1] = b;
    values[2] = c;
    values[3] = d;
};

int Matrix_2x2::inverseDeterminant() {
    int determinant = values[0]*values[3]-values[1]*values[2]
    // determinantX = 26Y + 1
    // determinantX - 26Y = 1
}