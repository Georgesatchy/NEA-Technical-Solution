#include <Python.h>
#include <iostream>
#include <string>

#include "text.hpp"
#include "ciphers/caesar.hpp"
#include "analyse.hpp"
#include "utils/matrix.hpp"

PyObject *decryptCaesar(PyObject *self, PyObject *args) {
    char* ciphertext;
    PyArg_ParseTuple(args, "s", &ciphertext);
    std::string str(ciphertext);
    PyObject *result = PyList_New(26);
    Text toDecrypt = Text(ciphertext);
    for (int i=0; i<26; i++) {
        PyObject* resultString = PyUnicode_FromString(caesar::decrypt(toDecrypt.caps, i).c_str());
        PyList_SET_ITEM(result, i, resultString);
    }
    return result;
};

PyObject *analyseCharFrequency(PyObject *self, PyObject *args) {
    char* textInput;
    PyArg_ParseTuple(args, "s", &textInput);
    float score = analyse::charFrequency(textInput);
    return PyLong_FromDouble(score);
};

PyObject *test(PyObject *self, PyObject *args) {
    std::cout << "a" << std::endl;
    Matrix_2x2 matrix = Matrix_2x2::Matrix_2x2(4, 1, 1, 3);
    std::cout << "e" << std::endl;
    int modDet = matrix.inverseDeterminant();
    std::cout << modDet << std::endl;
    return PyLong_FromDouble(modDet);
}

static PyMethodDef methods[] {
    {"caesar", decryptCaesar, METH_VARARGS, "Returns all Caesar shifts of a given string"},  
    {"char_frequency", analyseCharFrequency, METH_VARARGS, "Returns character frequency score for a given string"},  
    {"test", test, METH_VARARGS, "Function for testing"},  
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