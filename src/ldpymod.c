#include <Python.h>
#include <stddef.h>

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

    return m;
}
