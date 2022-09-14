#pragma once
using namespace std;
class Paralelogramo {
private:
    int a;
    int b;
    int h;
    // virtual string centrar(string, int);
    // virtual string rellenar(string, int);
    // virtual string centrarV2(string);
public:
    Paralelogramo();
    Paralelogramo(int a, int b, int h);
    ~Paralelogramo();
    virtual void dibujar();
    //void leer();
    //string rellenar();
};