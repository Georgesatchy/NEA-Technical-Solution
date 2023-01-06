#include "matrix.hpp"

int mod26(int a) {
    return (a % 26 + 26) % 26;
};

Matrix_2x2::Matrix_2x2(int a, int b, int c, int d) {
    values[0] = a;
    values[1] = b;
    values[2] = c;
    values[3] = d;
};

std::string Matrix_2x2::toString() {
    return 
        std::to_string(values[0]) + 
        ' ' + 
        std::to_string(values[1]) + 
        '\n' + 
        std::to_string(values[2]) + 
        ' ' + 
        std::to_string(values[3]);
};

Matrix_2x2 operator* (const Matrix_2x2& matrix, int y) {
    Matrix_2x2 result = Matrix_2x2(
        matrix.values[0] * y,
        matrix.values[1] * y,
        matrix.values[2] * y,
        matrix.values[3] * y
    );
    return result;
};

int determinant(int a, int b, int c, int d) {
    return a*d-b*c;
};

int Matrix_2x2::inverseDeterminant() {
    Matrix_2x2 coefficients(1, 0, 0, 1);
    int resultVector[2] = {mod26(determinant(values[0], values[1], values[2], values[3])), 26};
    int multiple;
    int temp;
    // Together (coefficients | resultVector) forms an augmented matrix
    while (resultVector[0] && resultVector[1]) {
        multiple = resultVector[1] / resultVector[0];
        temp = coefficients.values[2] - multiple*coefficients.values[0];
        coefficients.values[2] = coefficients.values[0];
        coefficients.values[0] = temp;
        temp = coefficients.values[3] - multiple*coefficients.values[1];
        coefficients.values[3] = coefficients.values[1];
        coefficients.values[1] = temp;
        temp = resultVector[1] - multiple*resultVector[0];
        resultVector[1] = resultVector[0];
        resultVector[0] = temp;
    };
    return mod26(coefficients.values[2]);
};

Matrix_2x2 Matrix_2x2::inverse() {
    Matrix_2x2 transpose = Matrix_2x2(mod26(values[3]), mod26(-values[1]), mod26(-values[2]), mod26(values[0]));
    return transpose*inverseDeterminant();
};

Matrix_3x3::Matrix_3x3(int a, int b, int c, int d, int e, int f, int g, int h, int i) {
    values[0] = a;
    values[1] = b;
    values[2] = c;
    values[3] = d;
    values[4] = e;
    values[5] = f;
    values[6] = g;
    values[7] = h;
    values[8] = i;
};


std::string Matrix_3x3::toString() {
    return 
        std::to_string(values[0]) + 
        ' ' + 
        std::to_string(values[1]) + 
        ' ' + 
        std::to_string(values[2]) + 
        '\n' + 
        std::to_string(values[3]) + 
        ' ' + 
        std::to_string(values[4]) + 
        ' ' + 
        std::to_string(values[5]) + 
        '\n' + 
        std::to_string(values[6]) + 
        ' ' + 
        std::to_string(values[7]) + 
        ' ' + 
        std::to_string(values[8]);
};


Matrix_3x3 operator* (const Matrix_3x3& matrix, int y) {
    Matrix_3x3 result = Matrix_3x3(
        mod26(matrix.values[0] * y),
        mod26(matrix.values[1] * y),
        mod26(matrix.values[2] * y),
        mod26(matrix.values[3] * y),
        mod26(matrix.values[4] * y),
        mod26(matrix.values[5] * y),
        mod26(matrix.values[6] * y),
        mod26(matrix.values[7] * y),
        mod26(matrix.values[8] * y)
    );
    return result;
};

int Matrix_3x3::inverseDeterminant() {
    Matrix_2x2 matrix1 = Matrix_2x2(values[4], values[5], values[7], values[8]);
    Matrix_2x2 matrix2 = Matrix_2x2(values[3], values[5], values[6], values[8]);
    Matrix_2x2 matrix3 = Matrix_2x2(values[3], values[4], values[6], values[7]);
    int result = values[0]*matrix1.inverseDeterminant() - values[1]*matrix2.inverseDeterminant() + values[2]*matrix3.inverseDeterminant();
    return mod26(result);
};

Matrix_3x3 Matrix_3x3::inverse() {
    int det = inverseDeterminant();
    int minors[9] = {
        determinant(values[4], values[5], values[7], values[8]),
        determinant(values[3], values[5], values[6], values[8]),
        determinant(values[3], values[4], values[6], values[7]),
        determinant(values[1], values[2], values[7], values[8]),
        determinant(values[0], values[2], values[6], values[8]),
        determinant(values[0], values[1], values[6], values[7]),
        determinant(values[1], values[2], values[4], values[5]),
        determinant(values[0], values[2], values[3], values[5]),
        determinant(values[0], values[1], values[3], values[4])
    };
    return Matrix_3x3(
        minors[0], -minors[1], minors[2],
        -minors[3], minors[4], -minors[5],
        minors[6], -minors[7], minors[8]
    )*det;
}