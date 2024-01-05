#include "Cliente.h"

Cliente::Cliente() {
	dni = "00000000Z";
	nombre = "/0";
}

Cliente::Cliente(string dni, string nombre) {
	this->dni = dni;
	this->nombre = nombre;
}

istream& operator>>(istream& is, Cliente& client) {
	cout << "Introduce el nombre: ";
	is >> client.nombre;
	cout << "Introduce el dni: ";
	is >> client.dni;
	return is;
}
ostream& operator<<(ostream& os, const Cliente& client) {
	os << "Nombre del cliente: " << client.nombre << " con DNI " << client.dni;
	return os;
}