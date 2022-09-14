#include "Triangulo.h"
#include <string>
#include <fstream>
#include <regex>
#include <iostream>

using namespace std;

Triangulo::Triangulo(int a, int b, int c, int h)
{
    this->a = a;
    this->b = b;
    this->c = c;
    this->h = h;
}

Triangulo::~Triangulo()
{
}

string centrarTriangulo(string cadena, int espacio)
{

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

string rellenarTriangulo(string cadena_a, int tamano){
    for (int i = 0; i < tamano; i++)
    {
        cadena_a += " ";
    }

    return cadena_a;
}

string centrarV2Triangulo(string desarrollo_a){
    if (desarrollo_a.length() == 1)
    {
        desarrollo_a = " " + desarrollo_a + " ";
    }
    else if (desarrollo_a.length() == 2)
    {
        desarrollo_a = " " + desarrollo_a;
    }

    return desarrollo_a;
}

void Triangulo::dibujar()
{
    fstream archivo("Triangulo.txt", ios::out | ios::in);

    // los numeros los paso a string
    string cadena_a = to_string(a);
    string cadena_h = to_string(h);
    string cadena_b = to_string(b);
    string cadena_c = to_string(c);

    string desarrollo_a = to_string(a);
    string desarrollo_h = to_string(h);
    string desarrollo_b = to_string(b);
    string desarrollo_c = to_string(c);
    // string cadena_a;

    //--- Figura ---------

    cadena_c = rellenarTriangulo(cadena_c, 3 - cadena_c.length());

    cadena_h = rellenarTriangulo(cadena_h, 3 - cadena_h.length());

    cadena_b = rellenarTriangulo(cadena_b, 3 - cadena_b.length());

    cadena_a = rellenarTriangulo(cadena_a, 3 - cadena_a.length());

    //---- Desarrollo ------------------------------------

    desarrollo_a = centrarV2Triangulo(desarrollo_a);

    desarrollo_h = centrarV2Triangulo(desarrollo_h);

    desarrollo_b = centrarV2Triangulo(desarrollo_b);

    desarrollo_c = centrarV2Triangulo(desarrollo_c);

    //--------------------------------

    int s = a + b + c;
    string suma = to_string(s);
    suma = centrarTriangulo(suma, 5);//esto ya esta

    int multi = b * h;
    string cadena_multi = to_string(multi);
    cadena_multi = centrarTriangulo(cadena_multi, 8);//esto ya esta

    int area = multi/2;
    string stringarea = to_string(area);
    stringarea = centrarTriangulo(stringarea, 8);

    string cadena;
    
    regex regex_a ("\\[a\\]");
    regex regex_b ("\\[b\\]");
    regex regex_c ("\\[c\\]");
    regex regex_h ("\\[h\\]");
    regex perimetro("\\{\\[t\\]\\}");//esta va

    while (getline(archivo, cadena))
    {
        
        cadena = regex_replace(cadena, perimetro, suma);
        cout << cadena << endl;
    }
}