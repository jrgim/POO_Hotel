#include "ClienteEsporadico.h"

ClienteEsporadico::ClienteEsporadico() {
	dni = "00000000Z";
	nombre = "/0";
	tipoCliente = 1;
}
ClienteEsporadico::ClienteEsporadico(string dni, string nombre) {
	this->dni = dni;
	this->nombre = nombre;
}
/*
int ClienteEsporadico::ObtenerDescuento()const {
	cout << "Los clientes esporadicos no tienen descuento" << endl;
	return 0;
}*/
bool ClienteEsporadico::nuevoDescuento(int descuento) {
	return false;
}
float ClienteEsporadico::aplicarDescuento(float precio) {
	cerr << "No se puede aplicar descuento a un cliente esporadico."<<endl;
	return precio;
}