#pragma once
#include <iostream>
using namespace std;

class Cliente
{
private:
	string dni;
	string nombre;
	// Poner tipo de cliente
public:
	Cliente();
	Cliente(string, string); //queda poner el tipo de cliente
	void ObtenerDatosCliente(const Cliente&);//Constante no quiero cambiar los datos
	void CargarDatosCliente(Cliente clienteIntroducir);
	void ObtenerDescuento(const Cliente&); //No cambiar datos
	friend istream& operator>>(istream&, Cliente&);
};

