#include "Habitacion.h"
Habitacion::Habitacion() {
	disponible = true;
	huespedes = 0;
}
bool Habitacion::Disponibilidad(const Habitacion& habitacionIntroducida) {
	return habitacionIntroducida.disponible;
}