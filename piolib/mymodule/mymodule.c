#include <Python.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "piolib.h"
#include "ws2812.pio.h"

static PyObject* test(PyObject *self, PyObject *args) {
    printf("test\n");
    
    Py_RETURN_NONE;
}

//what if we re-setup the pio each time. Is this really necessary? Maybe look into using module state memory

static PyObject* testpio(PyObject *self, PyObject *args) {
    PIO pio;
    
    pio = pio0;
    printf("testpio\n");
    
    //pio_close(pio);
    printf("closing pio\n");
    
    Py_RETURN_NONE;
}


// Exported methods are collected in a table
PyMethodDef method_table[] = {
    {"test", (PyCFunction) test, METH_VARARGS, "Method docstring"},
    {"testpio", (PyCFunction) testpio, METH_VARARGS, "Method docstring"},
    {NULL, NULL, 0, NULL} // Sentinel value ending the table
};

// A struct contains the definition of a module
PyModuleDef mymodule_module = {
    PyModuleDef_HEAD_INIT,
    "mymodule", // Module name
    "This is the module docstring",
    -1,   // Optional size of the module state memory
    method_table,
    NULL, // Optional slot definitions
    NULL, // Optional traversal function
    NULL, // Optional clear function
    NULL  // Optional module deallocation function
};

// The module init function
PyMODINIT_FUNC PyInit_mymodule(void) {
    return PyModule_Create(&mymodule_module);
}

