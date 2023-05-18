#include <Python.h>
#include <stdio.h>

void    fizzbuzz(int n)
{
    int     i;
    char    test1, test2;

    i = 0;
    while (++i <= n)
    {
        test1 = !(i % 3);
        test2 = !(i % 5);
        if (test1)
        { 
            if (test2)
                printf("fizzbuzz\n");
            else
                printf("fizz\n");
        }
        else if (test2)
            printf("buzz\n");
        else
            printf("%d\n", i);
    }
}

PyObject	*cFizzBuzz_method(PyObject *self, PyObject *args)
{
	int	n;

	if (!PyArg_ParseTuple(args, "i", &n))
		Py_RETURN_NONE;

	fizzbuzz(n);
	Py_RETURN_NONE;
}

static PyObject	*version(PyObject *self, PyObject *args)
{
	return (Py_BuildValue("s", "Version 0.0.1"));
}

static PyMethodDef FizzyBuzzy[] = {
	
	{"fizzbuzz", cFizzBuzz_method, METH_VARARGS,
		"Method calling fizzbuzz in C. Takes 1 int with which to count up to fizzbuzz style."},
	{"version", version, METH_NOARGS,
		"Returns FizzBuzz module version."},
	{NULL, NULL, 0, NULL}
};

static struct PyModuleDef cFizzBuzz = {
	PyModuleDef_HEAD_INIT,
	"cFizzBuzz",
	"A funny module playing fizzbuzz in C",
	-1,
	FizzyBuzzy	
};

PyMODINIT_FUNC	PyInit_cFizzBuzz(void)
{
	return (PyModule_Create(&cFizzBuzz));
}
/*
int main(void)
{
    fizzBuzz(15);
    return (0);
}
*/
