#pragma once
class Triangulo
{
private:
    int a,b,c,h;
    // virtual string centrarTriangulo(string, int);
    // virtual string rellenarTriangulo(string, int);
    // virtual string centrarV2Triangulo(string);
public:
    Triangulo(int,int,int,int);
    ~Triangulo();
    virtual void dibujar();
};


