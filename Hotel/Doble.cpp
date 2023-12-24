#include "Doble.h"
Doble::Doble() {
	Precio = 120.85;
}
Doble::Doble(bool disponible, int huespedes, int numHabitacion) {
	this->disponible = disponible;
	this->huespedes = huespedes;
	this->numHabitacion = 100 + numHabitacion;//(Habitaciones individuales del numero 100-199)
}
void Doble::ActualizarPrecio(float nuevoPrecio) {
	Precio = nuevoPrecio;
}