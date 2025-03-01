#include "Habitacion.h"
Habitacion::Habitacion() {
	disponible = true;
	huespedes = 0;
	Precio = 100;
	numHabitacion = 0;
}
float const Habitacion::ObtenerPrecioHabitacion() {
	return Precio;
}
bool Habitacion::Disponibilidad() {
	return disponible;
}
ostream& operator<<(ostream& os, const Habitacion& habitacion) {
	os <<habitacion.numHabitacion <<"\n" << habitacion.disponible << "\n" << habitacion.huespedes  << "\n" << habitacion.Precio;
	return os;
}
void Habitacion::llenarHabitacion(int huespedes) {
	this->huespedes = huespedes;
	disponible = false;
}
istream& operator>>(istream& is, Habitacion& habitacion) {
	is>> habitacion.numHabitacion >> habitacion.disponible >> habitacion.huespedes >> habitacion.Precio;
	return is;
}
void Habitacion::listaHabitaciones() {
	if (disponible) {
		cout << " esta disponible." << endl;
	}
	else {
		cout << " esta ocupada con " << huespedes << " huespedes." << endl;
	}
}
void Habitacion::numerar(int num) {
	numHabitacion = num;
}
void Habitacion::vaciarHabitacion() {
	disponible = true;
	huespedes = 0;
}