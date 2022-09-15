#pragma once
using namespace std;
class Rectangulo
{
private:
	int a;
	int b;
public:
	Rectangulo();
	Rectangulo(int a, int b);
	~Rectangulo();
	virtual void dibujar();
};
