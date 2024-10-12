#include <Python.h>

// https://docs.python.org/3/c-api/module.html#c.PyModuleDef
static struct PyModuleDef ldpymodmodule = {
    PyModuleDef_HEAD_INIT,
    "ldpymod",   /* name of module */
    "This is the documentation of this module.\n",
    -1,   /* size of per-interpreter state of the module, -1 = global variables. */
    NULL, NULL, NULL, NULL, NULL
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
