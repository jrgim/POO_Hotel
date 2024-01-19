#include "Cliente.h"

Cliente::Cliente() {
	dni = "00000000Z";
	nombre = "/0";
	descuento = 0;
	tipoCliente = -1;
}

Cliente::Cliente(string dni, string nombre) {
	this->dni = dni;
	this->nombre = nombre;
}

istream& operator>>(istream& is, Cliente& client) {
	is >> client.nombre >> client.dni >> client.tipoCliente>>client.descuento;
	return is;
}
ostream& operator<<(ostream& os, const Cliente& client) {
	os << client.nombre << "\n" << client.dni << "\n" << client.tipoCliente<<"\n"<<client.descuento;
	return os;
}
bool Cliente::ComprobarNombre(string nombreABuscar) {
	string nombreACorregir;
	if (nombre == nombreABuscar) {
		return true;
	}
	else return false;
}
int Cliente::ObtenerDescuento() {
	return descuento;
}
void Cliente::nuevoCliente() {
	cout << "Introduce el nombre: ";
	cin >> nombre;
	cout << "Introduce el dni: ";
	cin >> dni;
}
string Cliente::obtenerNombre() {
	return nombre;
}
void Cliente::leerCliente() {
	cout << "Nombre del cliente: " << nombre << " con DNI " << dni;
}
int Cliente::ObtenerTipoCliente() {
	return tipoCliente;
}
float Cliente::aplicarDescuento(float precio) {
	float descuentoFloat = static_cast<float>(descuento);
	float porcentaje = descuentoFloat / 100;
	float precioTotal = ((1 - porcentaje)*precio);
	return precioTotal;
}
bool Cliente::nuevoDescuento(int nuevoDescuento) {
	descuento = nuevoDescuento;

	return true;
}