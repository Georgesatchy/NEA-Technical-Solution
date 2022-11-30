#include <Python.h>
#include <iostream>
#include <string>

#include "text.hpp"
#include "caesar.hpp"
#include "analyse.hpp"

PyObject *caesar(PyObject *self, PyObject *args) {
    char* ciphertext;
    PyArg_ParseTuple(args, "s", &ciphertext);
    std::string str(ciphertext);
    PyObject *result = PyList_New(26);
    Text toDecrypt = Text(ciphertext);
    for (int i=0; i<26; i++) {
        Caesar c = Caesar(toDecrypt, i);
        PyObject* resultString = PyUnicode_FromString(c.decrypt().raw.c_str());
        PyList_SET_ITEM(result, i, resultString);
    }
    return result;
};

PyObject *charFrequency(PyObject *self, PyObject *args) {
    char* textInput;
    PyArg_ParseTuple(args, "s", &textInput);
    float score = charFrequency(textInput);
    return PyLong_FromDouble(score);
};

static PyMethodDef methods[] {
    {"caesar", caesar, METH_VARARGS, "Returns all Caesar shifts of a given string"},  
    {"char_frequency", charFrequency, METH_VARARGS, "Returns character frequency score for a given string"},  
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