#include "Cliente.h"

Cliente::Cliente() {
	dni = "00000000Z";
	nombre = "/0";
}

Cliente::Cliente(string dni, string nombre) {
	this->dni = dni;
	this->nombre = nombre;
}
void Cliente::ObtenerDatosCliente(const Cliente& cliente) {
	cout << "- Nombre: " << cliente.nombre << endl;
	cout << "- Dni: " << cliente.dni << endl;
}

void Cliente::ObtenerDescuento(const Cliente& cliente) {
	cout << "El descuento del cliente: " << cliente.nombre << " es de " ;//corregir, no se ha pasado el descuento
}
istream& operator>>(istream& is, Cliente& client) {
	cout << "Introduce el nombre: ";
	is >> client.nombre;
	cout << "Introduce el dni: ";
	is >> client.dni;
	return is;
}