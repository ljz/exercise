#include <Python.h>

int 
main(int argc, char *argv[]){
Py_SetProgramName(argv[0]);
Py_Initialize();
PyRun_SimpleString("print 'sdfjsdflsdjfhello world'");
Py_Finalize();

return 0;
}
