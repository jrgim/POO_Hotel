#pragma once
#include "Cliente.h"
class ClienteHabitual : public Cliente
{
private:
	//int descuento;
public:
	ClienteHabitual();
	ClienteHabitual(string, string, int);
	//int ObtenerDescuento() const;
	bool nuevoDescuento(int);
};

