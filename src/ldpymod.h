#ifndef LDPYMOD_H
#define LDPYMOD_H

#include <Python.h>
#include <structmember.h>
#include <libtrap/trap.h>
#include <unirec/unirec.h>
#include <unistd.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

PyAPI_DATA(PyObject *) GeneralError;
PyAPI_DATA(PyObject *) SpecificError;



#ifdef __cplusplus
}
#endif

#endif

