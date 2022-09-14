#pragma once
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <string>
#include <regex>
#include "Paralelogramo.h"

using namespace std;

void imprimirerror()
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    cout << "Uso: Figuras_Planas.exe ACCION [VARIABLES] \n";
    cout << setw(54) << "Calculos de perímetro y área de Figuras Planas. \n";
    cout << setw(13) << "Donde: \n";
    cout << setw(19) << "ACCION:" << endl;
    cout << setw(25) << "" << left << setw(20) << "ayuda"
        << "|"
        << " Información sobre el usa del programa." << endl
        << endl;
    cout << setw(25) << "" << left << setw(20) << "triangulo"
        << "|"
        << " VARIABLES: a b c h" << endl;

    cout << setw(25) << "" << left << setw(20) << "paralelogramo"
        << "|"
        << " VARIABLES: a b h" << endl;

    cout << setw(25) << "" << left << setw(20) << "rectangulo"
        << "|"
        << " VARIABLES: a b" << endl;

    cout << setw(25) << "" << left << setw(20) << "cuadrado"
        << "|"
        << " VARIABLES: a" << endl;

    cout << setw(25) << "" << left << setw(20) << "rombo"
        << "|"
        << " VARIABLES: a d D" << endl;

    cout << setw(25) << "" << left << setw(20) << "cometa"
        << "|"
        << " VARIABLES: a b d D" << endl;

    cout << setw(25) << "" << left << setw(20) << "trapecio"
        << "|"
        << " VARIABLES: a b c h B" << endl;

    cout << setw(25) << "" << left << setw(20) << "circulo"
        << "|"
        << " VARIABLES: r" << endl
        << endl;
}

void programa(int argc, char* argv[])
{
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    string forma = argv[1];
    cout << forma << endl;

    switch (argc)
    {
    case 3:
        /* ciculo y cuadrado */

        if (forma == "circulo")
        {
        }
        else if (forma == "cuadrado")
        {
        }
        else
        {
            // imprimirerror();
        }

        break;
    case 4:
        /* rectangulo */

        if (forma == "rectangulo")
        {
        }
        else
        {
            // imprimirerror();
        }

        break;
    case 5:
        /* rombo y paralelogramo */

        if (forma == "rombo")
        {
        }
        else if (forma == "paralelogramo")
        {

            int primero = atoi(argv[2]);
            int segundo = atoi(argv[3]);
            int tercero = atoi(argv[4]);
            // cout << "forma" << forma << endl;
            // cout << "primero" << primero << endl;
            // cout << "segundo" << segundo << endl;
            // cout << "tercero" << tercero << endl;
            // cout << "entro a paralelogramo" << endl;

            if (primero > 999 | segundo > 999 | tercero > 999)
            {
                cout << "Ingrese valores menores a 999 " << endl;
            }
            else
            {
                Paralelogramo p(primero, segundo, tercero);
                p.dibujar();
                //p.~Paralelogramo();
            }
        }
        else
        {
            // imprimirerror();
        }

        break;
    case 6:
        /* cometa  y triangulo */

        if (forma == "cometa")
        {
        }
        else if (forma == "triangulo")
        {
        }
        else
        {
            // imprimirerror();
        }

        break;
    case 7:
        /* trapecio */

        if (forma == "trapecio")
        {
        }
        else
        {
            // imprimirerror();
        }
        break;

    default:
        break;
    }

    //[0] path
    //[1] forma
    //[2] numero 1
    //[3] numero 2
    //[4] numero 3
    //[5] numero 4
}