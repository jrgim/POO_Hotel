#include "ClienteEsporadico.h"

ClienteEsporadico::ClienteEsporadico() {
	dni = "00000000Z";
	nombre = "/0";
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