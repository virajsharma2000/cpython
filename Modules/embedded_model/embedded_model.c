#include <Python.h>
#include "model_data.h"
#include "tensorflow/lite/c/c_api.h"

static PyObject* py_infer(PyObject *self, PyObject *args) {
    PyObject* input;
    if (!PyArg_ParseTuple(args, "O", &input)) {
        return NULL;
    }

    TfLiteModel* model = TfLiteModelCreate(mobilenet_v1_tflite,
                                           mobilenet_v1_tflite_len);
    if (!model) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to load model");
        return NULL;
    }

    // TODO: setup interpreter, allocate tensors, feed input, run inference

    TfLiteModelDelete(model);

    return Py_BuildValue("s", "inference complete");
}

static PyMethodDef Methods[] = {
    {"infer", py_infer, METH_VARARGS, "Run inference on embedded model"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "embedded_model",
    "Embedded TensorFlow Lite Model",
    -1,
    Methods
};

PyMODINIT_FUNC
PyInit_embedded_model(void) {
    return PyModule_Create(&moduledef);
}
