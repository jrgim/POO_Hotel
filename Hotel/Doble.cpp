#include "Doble.h"
Doble::Doble() {
	Precio = 120.85;
}
Doble::Doble(bool disponible, int huespedes) {
	this->disponible = disponible;
	this->huespedes = huespedes;
}