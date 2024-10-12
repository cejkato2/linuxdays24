#ifndef LDPYMOD_H
#define LDPYMOD_H

#include <Python.h>

#ifdef __cplusplus
extern "C" {
#endif

PyAPI_DATA(PyObject *) GeneralError;
PyAPI_DATA(PyObject *) SpecificError;

#ifdef __cplusplus
}
#endif

#endif

