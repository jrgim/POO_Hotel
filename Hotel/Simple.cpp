#include "Simple.h"
Simple::Simple() {
	Precio = 80.50;
}
Simple::Simple(bool disponible, int huespedes) {
	this->disponible = disponible;
	this->huespedes = huespedes;
}