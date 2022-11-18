#include <Python.h>
#include <iostream>
#include <string>
#include "caesar.hpp"

using namespace std;

PyObject *caesar(PyObject *self, PyObject *args) {
    cout << "Running Caesar function" << endl;
    char* ciphertext;
    PyArg_ParseTuple(args, "s", &ciphertext);
    string str(ciphertext);
    PyObject *result = PyList_New(26);
    for (int i=0; i<26; i++) {
        Caesar c = Caesar(ciphertext, i);
        PyObject* resultString = PyBytes_FromString(c.decrypt().c_str());
        PyList_SET_ITEM(result, i, resultString);
    }
    return result;
};

static PyMethodDef methods[] {
    {"caesar", caesar, METH_VARARGS, "Returns all Caesar shifts of a given string"},  
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
    cout << "Cipher tools loaded!" << endl;
    return PyModule_Create(&cipherModule);
};