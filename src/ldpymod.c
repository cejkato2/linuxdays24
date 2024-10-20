#include <Python.h>
#include <stddef.h>
#include "ldpymod.h"
#include "object.h"

PyObject *GeneralError;
PyObject *SpecificError;

PyObject *
ldpymod_hello(PyObject *self)
{
    const char *string = "Hello world!";
    int number = 1234;

    // https://docs.python.org/3/c-api/arg.html#c.Py_BuildValue
    return Py_BuildValue("(si)", string, number);
}

// https://docs.python.org/3/c-api/structures.html#c.PyMethodDef
static PyMethodDef ldpymod_methods[] = {
    {"hello", (PyCFunction) ldpymod_hello, METH_NOARGS,
     "Get tuple with string and number.\n\n"
     "Returns:\n"
     "    tuple(str, int)\n\n"},
    {NULL, NULL, 0, NULL}
};

// https://docs.python.org/3/c-api/module.html#c.PyModuleDef
static struct PyModuleDef ldpymodmodule = {
    PyModuleDef_HEAD_INIT,
    "ldpymod",   /* name of module */
    "This is the documentation of this module.\n",
    -1,   /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    ldpymod_methods,
    NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_ldpymod(void)
{
    PyObject *m;

    m = PyModule_Create(&ldpymodmodule);
    if (m == NULL) {
        return NULL;
    }

    if (PyType_Ready(&LinuxDaysObj) < 0) {
        return NULL;
    }
    Py_INCREF(&LinuxDaysObj);
    PyModule_AddObject(m, "LinuxDaysObj", (PyObject *) &LinuxDaysObj);

    /* Add Exceptions into pytrap module */
    GeneralError = PyErr_NewException("ldpymod.GeneralError", NULL, NULL);
    Py_INCREF(GeneralError);
    PyModule_AddObject(m, "GeneralError", GeneralError);

    SpecificError = PyErr_NewException("ldpymod.SpecificError", GeneralError, NULL);
    Py_INCREF(SpecificError);
    PyModule_AddObject(m, "SpecificError", SpecificError);

    /* Add constants into pytrap module */
    PyModule_AddIntConstant(m, "FMT_RAW", 1);
    PyModule_AddIntConstant(m, "FMT_JSON", 2);

    return m;

}
