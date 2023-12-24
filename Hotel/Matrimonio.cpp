#include "Matrimonio.h"
Matrimonio::Matrimonio() {
	Precio = 180.4;
}

Matrimonio::Matrimonio(bool disponible, int huespedes) {
	this->disponible = disponible;
	this->huespedes = huespedes;
}