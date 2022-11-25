#include <Python.h>
#include <iostream>
#include <string>
#include "caesar.hpp"
#include "analyse.hpp"

using namespace std;

PyObject *caesar(PyObject *self, PyObject *args) {
    cout << "Running Caesar function" << endl;
    char* ciphertext;
    PyArg_ParseTuple(args, "s", &ciphertext);
    string str(ciphertext);
    PyObject *result = PyList_New(26);
    for (int i=0; i<26; i++) {
        Caesar c = Caesar(ciphertext, i);
        PyObject* resultString = PyUnicode_FromString(c.decrypt().c_str());
        PyList_SET_ITEM(result, i, resultString);
    }
    return result;
};

PyObject *charFrequency(PyObject *self, PyObject *args) {
    cout << "Running character frequency analysis function" << "\n";
    char* text;
    PyArg_ParseTuple(args, "s", &text);
    string str(text);
    Analyse a = Analyse(text);
    float score = a.charFrequency();
    cout << score << "\n";
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
    cout << "Cipher tools loaded!" << endl;
    return PyModule_Create(&cipherModule);
};