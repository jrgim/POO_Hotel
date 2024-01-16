#pragma once
#include <iostream>
#include "ClienteEsporadico.h"
#include "ClienteHabitual.h"
using namespace std;

class Cliente
{
protected://protected para que puedan acceder las hijas
	string dni;
	string nombre;
	int descuento;
	int tipoCliente;
public:
	Cliente();
	Cliente(string, string);
	int ObtenerDescuento();/*const= 0*///Si lo hago virtual puro no me sale aunque lo haga solo en las hijas. no funciona el array en el hotel
	bool ComprobarNombre(string);
	int ObtenerTipoCliente();
	void nuevoCliente();
	void leerCliente();
	string obtenerNombre();
	virtual float aplicarDescuento(float);
	virtual void numerar() = 0;
	bool nuevoDescuento(int);
	friend istream& operator>>(istream&, Cliente*&);
	friend ostream& operator<<(ostream&, const Cliente&);
};

