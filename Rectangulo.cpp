#include "Rectangulo.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <string>
#include <regex>

Rectangulo::Rectangulo()
{
}

Rectangulo::~Rectangulo()
{
}

Rectangulo::Rectangulo(int a, int b)
{
    this->a = a;
    this->b = b;
}

string centrar(string cadena, int espacio) {

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

string rellenar(string ladoo, int tamano) {
    for (int i = 0; i < tamano; i++)
    {
        ladoo += " ";
    }

    return ladoo;
}

string centrarV2(string lad) {
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

void Rectangulo::dibujar()
{
    fstream archivo("Rectangulo.txt", ios::out | ios::in);

    // los numeros los paso a string
    string ladoo = to_string(a);
    string bbbbb = to_string(b);

    string lad = to_string(a);
    string bbb = to_string(b);
    // string ladoo;

    //--- Figura ---------

    ladoo = rellenar(ladoo, 3 - ladoo.length());


    bbbbb = rellenar(bbbbb, 3 - bbbbb.length());

    //---- Desarrollo ------------------------------------

    lad = centrarV2(lad);

    /*if (lad.length() == 1)
    {
        lad = " " + lad + " ";
    }
    else if (lad.length() == 2)
    {
        lad = " " + lad;
    }*/


    bbb = centrarV2(bbb);

    /*if (bbb.length() == 1)
    {
        bbb = " " + bbb + " ";
    }
    else if (bbb.length() == 2)
    {
        bbb = " " + bbb;
    }*/

    //--------------------------------

    int s = a + b;
    string suma = to_string(s);
    suma = centrar(suma, 5);


    int totalpp = s * 2;
    string stotalpp = to_string(totalpp);
    stotalpp = centrar(stotalpp, 9);


    int area = b * a;
    string stringarea = to_string(area);
    stringarea = centrar(stringarea, 7);

    string cadena;
    string tc = "total";
    regex regexp("lad");
    regex regexb("bbb");
    regex r1("--l");
    regex r3("--b");
    regex r4("sssss");
    regex totalp("\\[\\{2\\*a\\+b\\}\\]");
    regex regexarea("\\[\\{b\\*a\\}\\]");


    while (getline(archivo, cadena))
    {
        cadena = regex_replace(cadena, regexp, ladoo);
        cadena = regex_replace(cadena, regexb, bbbbb);
        cadena = regex_replace(cadena, r1, lad);
        cadena = regex_replace(cadena, r3, bbb);
        cadena = regex_replace(cadena, r4, suma);
        cadena = regex_replace(cadena, totalp, stotalpp);
        cadena = regex_replace(cadena, regexarea, stringarea);
        cout << cadena << endl;
    }
}