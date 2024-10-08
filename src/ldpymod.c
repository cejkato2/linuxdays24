#include "ldpymod.h"


static struct PyModuleDef ldpymodmodule = {
    PyModuleDef_HEAD_INIT,
    "ldpymod",   /* name of module */
    "This is the documentation of this module.\n",
    -1,   /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    pytrap_methods, NULL, NULL, NULL, NULL
};

PyMODINIT_FUNC
PyInit_pytrap(void)
{
    PyObject *m;

    m = PyModule_Create(&pldpymodmodule);
    if (m == NULL) {
        INITERROR;
    }

    if (PyType_Ready(&LinuxDaysObj) < 0) {
        INITERROR;
    }
    Py_INCREF(&LinuxDaysObj);
    PyModule_AddObject(m, "LinuxDaysObj", (PyObject *) &LinuxDaysObj);

    /* Add Exceptions into pytrap module */
    GeneralError = PyErr_NewException("ldpymod.GeneralError", NULL, NULL);
    Py_INCREF(GeneralError);
    PyModule_AddObject(m, "GeneralError", GeneralError);

    SpecificError = PyErr_NewException("ldpymod.SpecificError", NULL, NULL);
    Py_INCREF(SpecificError);
    PyModule_AddObject(m, "SpecificError", SpecificError);

    /* Add constants into pytrap module */
    PyModule_AddIntConstant(m, "FMT_RAW", 1);
    PyModule_AddIntConstant(m, "FMT_JSON", 2);

    return m;
}
