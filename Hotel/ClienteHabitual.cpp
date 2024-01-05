#include "ClienteHabitual.h"
ClienteHabitual::ClienteHabitual() {
	dni = "00000000Z";
	nombre = "/0";
	descuento = 0;
}
ClienteHabitual::ClienteHabitual(string dni, string nombre, int descuento) {
	this->dni = dni;
	this->nombre = nombre;
	this->descuento = descuento;
}
int ClienteHabitual::ObtenerDescuento() const {
	cout << "El cliente tiene un deacuento de: " << descuento << "%" << endl;//Igual no hace falta
	return descuento;
}