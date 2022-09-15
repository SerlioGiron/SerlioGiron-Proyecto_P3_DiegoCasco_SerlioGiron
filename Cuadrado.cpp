#include "Cuadrado.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

Cuadrado::Cuadrado(int a)
{
    this->a = a;
}

Cuadrado::~Cuadrado()
{
}


string centrarCuadrado(string cadena, int espacio) {

    string temp = "";
    string temp2 = "";

    int ta = (((espacio + 1) - cadena.length()) / 2);

    for (int i = 0; i < ta; i++)
    {
        temp += " ";
    }
    for (int i = 0; i < ta - 1; i++)
    {
        temp2 += " ";
    }

    if (cadena.length() % 2 != 0)
    {
        cadena = temp + cadena + temp;
    }
    else
    {
        cadena = temp + cadena + temp2;
    }

    return cadena;
}

string rellenarCuadrado(string ladoo, int tamano) {
    for (int i = 0; i < tamano; i++)
    {
        ladoo += " ";
    }

    return ladoo;
}

string centrarV2Cuadrado(string lad) {
    if (lad.length() == 1)
    {
        lad = " " + lad + " ";
    }
    else if (lad.length() == 2)
    {
        lad = " " + lad;
    }

    return lad;
}

void Cuadrado::dibujar()
{
    fstream archivo("cuadrado.txt", ios::out | ios::in);

    // los numeros los paso a string
    string cadena_a = to_string(a);
    // string ladoo;

    //--- Figura ---------

    cadena_a = rellenarCuadrado(cadena_a, 3 - cadena_a.length());

    //---- Desarrollo ------------------------------------

    

    //--------------------------------

    int perimetro = a * 4;
    string cadena_perimetro = to_string(perimetro);
    cadena_perimetro = centrarCuadrado(cadena_perimetro, 5);


    int area = a * a;
    string stringarea = to_string(area);
    stringarea = centrarCuadrado(stringarea,7);

    string cadena;
    regex regex_a("\\[\\{a\\}\\]");
    regex regex_perimetro("\\[4 \\* \\{a\\}\\]");

    cout << "Hola" << endl;

    while (getline(archivo, cadena))
    {
        cadena = regex_replace(cadena, regex_perimetro, cadena_perimetro);
        cadena = regex_replace(cadena, regex_a, cadena_a);
        cout << cadena << endl;
    }
}