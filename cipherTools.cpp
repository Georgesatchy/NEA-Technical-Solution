#include <Python.h>
#include <stdio.h>
#include <string>

using namespace std;

PyObject *caeser(PyObject *self, PyObject *args) {
    printf("Running Caeser function\n");
    const char* ciphertext;
    PyArg_ParseTuple(args, "s", &ciphertext);
    PyObject *result = PyList_New(26);
    for (int i=0; i<26; i++) {
        PyObject* resultString = PyBytes_FromString(ciphertext);
        PyList_SET_ITEM(result, i, resultString);
    }
    return result;
};

static PyMethodDef methods[] {
    {"caeser", caeser, METH_VARARGS, "Returns all Caeser shifts of a given string"},  
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
    printf("Cipher tools loaded!\n");
    return PyModule_Create(&cipherModule);
};