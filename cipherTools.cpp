#include <Python.h>
#include <stdio.h>
#include <string>

using namespace std;

static PyMethodDef methods[] {
    {}
};

static struct PyModuleDef cipherModule = {
    PyModuleDef_HEAD_INIT,
    "Cipher Tools",
    "Cipher tools module for NEA",
    -1,
    methods
};

PyMODINIT_FUNC PyInit_cipherTools() {
    printf("Cipher tools loaded!");
    return PyModule_Create(&cipherModule);
};