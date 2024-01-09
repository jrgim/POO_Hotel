#include "Habitacion.h"
Habitacion::Habitacion() {
	disponible = true;
	huespedes = 0;
	Precio = 100;
	numHabitacion = 0;//igual quitar, se calculara con el indice del array
}
float const Habitacion::ObtenerPrecioHabitacion() {
	cout << "El precio de la habitacion es de: " << Precio << "Euros\n\n" << endl;//igual quitar
	return Precio;
}
bool Habitacion::Disponibilidad() {
	return disponible;
}
ostream& operator<<(ostream& os, const Habitacion& habitacion) {
	if (habitacion.disponible) {
		os << " esta disponible." << endl;
	}
	else {
		os << " esta ocupada con " << habitacion.huespedes << " huespedes." << endl;
	}

	return os;
}
istream& operator>>(istream& is, Habitacion& habitacion) {
	cout << "Numero de Huespedes: ";
	is >> habitacion.huespedes;
	habitacion.disponible = false;
	return is;
}