/* Minimal main program -- everything is loaded from the library */

#include "Python.h"

#ifdef MS_WINDOWS
int
wmain(int argc, wchar_t **argv)
{
    printf("=== Viraj's Fantastic Python v%s (%s build) ===\n", PY_VERSION, __DATE__);
    return Py_Main(argc, argv);
}
#else
int
main(int argc, char **argv)
{
    printf("=== Viraj's Fantastic Python v%s (%s build) ===\n", PY_VERSION, __DATE__);
    return Py_BytesMain(argc, argv);
}
#endif
