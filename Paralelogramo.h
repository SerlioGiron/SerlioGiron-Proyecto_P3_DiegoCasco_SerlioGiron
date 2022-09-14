#pragma once
using namespace std;
class Paralelogramo {
private:
    int a;
    int b;
    int h;
    int area;
    int perimetro;
public:
    Paralelogramo();
    Paralelogramo(int a, int b, int h);
    ~Paralelogramo();
    void dibujar();
    void leer();
    //string rellenar();
};