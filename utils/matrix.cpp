#include "matrix.hpp"

Matrix_2x2::Matrix_2x2(int a, int b, int c, int d) {
    values[0] = a;
    values[1] = b;
    values[2] = c;
    values[3] = d;
};

int Matrix_2x2::inverseDeterminant() {
    int determinant = values[0]*values[3]-values[1]*values[2];
    std::cout << determinant << std::endl;
    Matrix_2x2 coefficients(1, 0, 0, 1);
    int resultVector[2] = {determinant%26, 26};
    int multiple;
    // Together (coefficients | resultVector) forms an augmented matrix
    while (resultVector[0] && resultVector[1]) {
        std::cout << "0: " << resultVector[0] << std::endl;
        std::cout << "1: " << resultVector[1] << std::endl;
        multiple = resultVector[1] / resultVector[0];
        std::cout << coefficients.values[2] - multiple*coefficients.values[0] << std::endl;
        std::cout << coefficients.values[3] - multiple*coefficients.values[1] << std::endl;
        coefficients.values[0], coefficients.values[2] = coefficients.values[2] - multiple*coefficients.values[0], coefficients.values[0];
        coefficients.values[1], coefficients.values[3] = coefficients.values[3] - multiple*coefficients.values[1], coefficients.values[1];
        resultVector[0], resultVector[1] = resultVector[1] - multiple*resultVector[0], resultVector[0]; // problem here
    };
    return coefficients.values[2]%26;
};