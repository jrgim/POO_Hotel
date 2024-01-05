#pragma once
#include <iostream>
using namespace std;

class Cliente
{
protected://protected para que puedan acceder las hijas
	string dni;
	string nombre;
public:
	Cliente();
	Cliente(string, string);
	virtual int ObtenerDescuento() const = 0;
	friend istream& operator>>(istream&, Cliente&);
	friend ostream& operator<<(ostream&, const Cliente&);
};

