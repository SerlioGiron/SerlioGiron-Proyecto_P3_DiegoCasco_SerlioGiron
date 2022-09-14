#include "Paralelogramo.h"
#include <iostream>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <string>
#include <regex>

Paralelogramo::Paralelogramo()
{
}

Paralelogramo::~Paralelogramo()
{
}


Paralelogramo::Paralelogramo(int a, int h, int b)
{
    this->a = a;
    this->b = b;
    this->h = h;
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

void Paralelogramo::dibujar()
{
    fstream archivo("paralelogramo_02.txt", ios::out | ios::in);

    // los numeros los paso a string
    string ladoo = to_string(a);
    string hhhhh = to_string(h);
    string bbbbb = to_string(b);

    string lad = to_string(a);
    string hhh = to_string(h);
    string bbb = to_string(b);
    // string ladoo;

    //--- Figura ---------

    ladoo = rellenar(ladoo, 3 - ladoo.length());

    hhhhh = rellenar(hhhhh, 3 - hhhhh.length());

    bbbbb = rellenar(bbbbb, 3 - bbbbb.length());

    //---- Desarrollo ------------------------------------

    //lad = centrar(lad, 5);
    
    if (lad.length() == 1)
    {
        lad = " " + lad + " ";
    }
    else if (lad.length() == 2)
    {
        lad = " " + lad;
    }

    //hhh = centrar(hhh, 5);

    if (hhh.length() == 1)
    {
        hhh = " " + hhh + " ";
    }
    else if (hhh.length() == 2)
    {
        hhh = " " + hhh;
    }

    if (bbb.length() == 1)
    {
        bbb = " " + bbb + " ";
    }
    else if (bbb.length() == 2)
    {
        bbb = " " + bbb;
    }

    //--------------------------------

    int s = a + b;
    string suma = to_string(s);
    suma = centrar(suma, 5);


    int totalpp = s * 2;
    string stotalpp = to_string(totalpp);
    stotalpp = centrar(stotalpp, 9);


    int area = b * h;
    string stringarea = to_string(area);
    stringarea = centrar(stringarea,7);

    string cadena;
    string tc = "total";
    regex regexp("lad");
    regex regexh("hhh");
    regex regexb("bbb");
    regex r1("--l");
    regex r2("--h");
    regex r3("--b");
    regex r4("sssss");
    regex totalp("\\[\\{2\\*a\\+b\\}\\]");
    regex regexarea("\\[\\{b\\*h\\}\\]");


    while (getline(archivo, cadena))
    {
        cadena = regex_replace(cadena, regexp, ladoo);
        cadena = regex_replace(cadena, regexh, hhhhh);
        cadena = regex_replace(cadena, regexb, bbbbb);
        cadena = regex_replace(cadena, r1, lad);
        cadena = regex_replace(cadena, r2, hhh);
        cadena = regex_replace(cadena, r3, bbb);
        cadena = regex_replace(cadena, r4, suma);
        cadena = regex_replace(cadena, totalp, stotalpp);
        cadena = regex_replace(cadena, regexarea, stringarea);
        cout << cadena << endl;
    }
}