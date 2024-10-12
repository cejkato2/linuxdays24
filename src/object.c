#include "ldpymod.h"
#include "object.h"
#include <math.h>

// Heron's formula
double triangle_area(double a, double b, double c) {
    // Výpočet polovičního obvodu
    double s = (a + b + c) / 2;

    // Výpočet plochy pomocí Heronova vzorce
    double area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}

PyObject *
ldobject_totalarea(PyObject *self, PyObject *args, PyObject *keywds)
{
    PyObject *tri_list, *side;
    double a, b, c;
    int coef_a = 1, coef_b = 1, coef_c = 1;
    double result = 0;

    static char *kwlist[] = {"triangles", "coef_a", "coef_b", "coef_c", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, keywds, "O!|iii", kwlist, &PyList_Type, &tri_list, &coef_a, &coef_b, &coef_c)) {
        return NULL;
    }

    Py_ssize_t len = PyList_Size(tri_list);
    for (Py_ssize_t i=0; i<len; ++i) {
        // get borrowed reference
        PyObject *triangle = PyList_GetItem(tri_list, i);

        if (!PyTuple_Check(triangle)) {
            PyErr_Format(PyExc_TypeError, "Item %i is not tuple.", i);
            return NULL;
        }
        if (PyTuple_Size(triangle) != 3) {
            PyErr_Format(PyExc_TypeError, "Triangle %i has not 3 sizes.", i);
            return NULL;
        }
        side = PyTuple_GetItem(triangle, 0);
        a = PyFloat_AsDouble(side) * coef_a;
        side = PyTuple_GetItem(triangle, 1);
        b = PyFloat_AsDouble(side) * coef_b;
        side = PyTuple_GetItem(triangle, 2);
        c = PyFloat_AsDouble(side) * coef_c;

        if ((a + b > c) && (a + c > b) && (b + c > a)) {
            result += triangle_area(a * coef_a, b * coef_b, c * coef_c);
        } else {
            PyErr_Format(SpecificError, "Triangle %i cannot exist in 2D space.", i);
            return NULL;
        }
    }
    return PyFloat_FromDouble(result);
}
// https://docs.python.org/3/c-api/structures.html#c.PyMethodDef
static PyMethodDef ldobject_methods[] = {
    {"area", (PyCFunction) ldobject_totalarea, METH_VARARGS | METH_KEYWORDS,
     "Compute space of triangles multiplied by coeficients.\n\n"
     "  Function expects list of tuples (triangles), and optionally three float coefficients (coef_a, coef_b, coef_c).\n"
     "  Coeficients are used to scale the sides of the triangle, the default is 1.\n\n"
     "Args:\n"
     "    triangles (list(tuple)): List of triangles (tuples) defined by 3 sides as float.\n"
     "    coef_a (Optional[int]): Coeficient to scale the side a.\n"
     "    coef_b (Optional[int]): Coeficient to scale the side b.\n"
     "    coef_c (Optional[int]): Coeficient to scale the side c.\n"
     "Returns:\n"
     "    float\n\n"
     "Raises:\n"
     "    SpecificError: Triangle cannot exist (maybe due to scaling?).\n"
     "    TypeError: Bad type of argument.\n"
    },
    {NULL, NULL, 0, NULL}
};

PyTypeObject LinuxDaysObj = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "ldpymod.LinuxDaysObj", /* tp_name */
    sizeof(LinuxDaysObj_s), /* tp_basicsize */
    0, /* tp_itemsize */
    0, /* tp_dealloc */
    0, /* tp_print */
    0, /* tp_getattr */
    0, /* tp_setattr */
    0, /* tp_reserved */
    0, /* tp_repr */
    0, /* tp_as_number */
    0, /* tp_as_sequence */
    0, /* tp_as_mapping */
    0, /* tp_hash  */
    0, /* tp_call */
    0, /* tp_str */
    0, /* tp_getattro */
    0, /* tp_setattro */
    0, /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE, /* tp_flags */
    "LinuxDaysObj()\n"
    "    Class documentation. See the area() method.\n", /* tp_doc */
    0, /* tp_traverse */
    0, /* tp_clear */
    0, /* tp_richcompare */
    0, /* tp_weaklistoffset */
    0, /* tp_iter */
    0, /* tp_iternext */
    ldobject_methods, /* tp_methods */
    0, /* tp_members */
    0, /* tp_getset */
    0, /* tp_base */
    0, /* tp_dict */
    0, /* tp_descr_get */
    0, /* tp_descr_set */
    0, /* tp_dictoffset */
    0, /* tp_init */
    0, /* tp_alloc */
    PyType_GenericNew  /* tp_new */
};


