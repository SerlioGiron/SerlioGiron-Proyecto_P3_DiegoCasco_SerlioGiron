#include <iostream>
#include <iomanip>
#include <windows.h>
#include <regex>
#include "Funciones.h"

int main(int argc, char* argv[])
{
    cout << "HELLO WORLD" << endl;
    if (argc < 2) {
        imprimirerror();
    }
    else {
        programa(argc, argv);
    }
}