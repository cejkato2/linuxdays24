#ifndef LDPYMOD_OBJECT_H
#define LDPYMOD_OBJECT_H


#ifdef __cplusplus
extern "C" {
#endif


typedef struct {
    PyObject_HEAD
    uint32_t counter;
} LinuxDaysObj_s;

PyAPI_DATA(PyTypeObject) LinuxDaysObj;

#ifdef __cplusplus
}
#endif

#endif
