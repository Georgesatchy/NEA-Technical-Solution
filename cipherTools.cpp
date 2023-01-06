#include <Python.h>
#include <iostream>
#include <string>

#include "text.hpp"
#include "ciphers/caesar.hpp"
#include "analyse.hpp"
#include "utils/matrix.hpp"

PyObject *autoDecrypt(PyObject *self, PyObject *args) {
    char* ciphertext;
    PyArg_ParseTuple(args, "s", &ciphertext);
    std::string toDecrypt = format(ciphertext);
    std::string caesarDecryption = caesar::bestSolution(format(ciphertext)).c_str();
    if 
};


PyObject *decryptCaesar(PyObject *self, PyObject *args) {
    char* ciphertext;
    PyArg_ParseTuple(args, "s", &ciphertext);
    std::string str(ciphertext);
    // Text toDecrypt = Text(ciphertext);
    // std::cout << toDecrypt.alphabetic << std::endl;
    PyObject* result = PyUnicode_FromString(caesar::bestSolution(format(ciphertext)).c_str());
    return result;
};

PyObject *analyseCharFrequency(PyObject *self, PyObject *args) {
    char* textInput;
    PyArg_ParseTuple(args, "s", &textInput);
    float score = analyse::charFrequency(textInput);
    return PyLong_FromDouble(score);
};

PyObject *inverse2x2(PyObject *self, PyObject *args) {
    int values[4] = {0};
    PyArg_ParseTuple(args, "iiii", &values[0], &values[1], &values[2], &values[3]);
    Matrix_2x2 matrix = Matrix_2x2::Matrix_2x2(values[0], values[1], values[2], values[3]);
    std::string inverse = matrix.inverse().toString();
    return PyUnicode_FromString(inverse.c_str());
}

PyObject *inverse3x3(PyObject *self, PyObject *args) {
    int values[9] = {0};
    PyArg_ParseTuple(args, "iiiiiiiii", &values[0], &values[1], &values[2], &values[3], &values[4], &values[5], &values[6], &values[7], &values[8]);
    Matrix_3x3 matrix = Matrix_3x3::Matrix_3x3(values[0], values[1], values[2], values[3], values[4], values[5], values[6], values[7], values[8]);
    std::string inverse = matrix.inverse().toString();
    return PyUnicode_FromString(inverse.c_str());
}

static PyMethodDef methods[] {
    {"caesar", decryptCaesar, METH_VARARGS, "Returns all Caesar shifts of a given string"},  
    {"char_frequency", analyseCharFrequency, METH_VARARGS, "Returns character frequency score for a given string"},  
    {"inverse2x2", inverse2x2, METH_VARARGS, "Function for finding modular (mod 26) inverse of a 2x2 matrix"},
    {"inverse3x3", inverse3x3, METH_VARARGS, "Function for finding modular (mod 26) inverse of a 3x3 matrix"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef cipherModule = {
    PyModuleDef_HEAD_INIT,
    "Cipher Tools",
    "Cipher tools module for NEA",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_cipherTools(void) {
    std::cout << "Cipher tools loaded!" << std::endl;
    return PyModule_Create(&cipherModule);
};