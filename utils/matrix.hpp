#ifndef __MATRIX__
#define __MATRIX__

class Matrix_2x2 {
    public:
        Matrix_2x2(int a, int b, int c, int d); // The 4 values inside of the matrix
        int values[4];
        Matrix_2x2 inverse();
        int * multiply(int vector[2]);
    private:
        int inverseDeterminant();
};

class Matrix_3x3 {
    public:
        int values[9];
        Matrix_3x3 inverse();
        int * multiply(int vector[3]);
    private:
        int inverseDeterminant();
};

#endif