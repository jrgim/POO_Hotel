#include "Simple.h"
Simple::Simple() {
	Precio = 80.50;
}
Simple::Simple(bool disponible, int huespedes, int numHabitacion) {
	this->disponible = disponible;
	this->huespedes = huespedes;
	this->numHabitacion = numHabitacion;
}
void Simple::ActualizarPrecio(float nuevoPrecio) {
	Precio = nuevoPrecio;
}
float Simple::ObtenerPrecioHabitacion() const{
	cout << "El precio de la habitacion simple X noche es de: " << Precio << "Euros." << endl;//igual quitar
	return Precio;
}