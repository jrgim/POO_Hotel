#include "Matrimonio.h"
Matrimonio::Matrimonio() {
	Precio = 180.4;
}

Matrimonio::Matrimonio(bool disponible, int huespedes, int numHabitacion) {
	this->disponible = disponible;
	this->huespedes = huespedes;
	this->numHabitacion = 200 + numHabitacion; //Habitaciones de matrimonio a partir del 200
}
void Matrimonio::ActualizarPrecio(float nuevoPrecio) {
	Precio = nuevoPrecio;
}
void Matrimonio::numerar(int num) {
	numHabitacion = (num + 200);
}
float Matrimonio::ObtenerPrecioHabitacion() const {
	cout << "El precio de la habitacion de matrimonio X noche es de: " << Precio << "Euros." << endl;//igual quitar
	return Precio;
}