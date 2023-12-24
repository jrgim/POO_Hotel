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