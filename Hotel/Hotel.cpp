#include "Hotel.h"
Hotel::Hotel() {
	habitacionesSimples = new Simple[numMaxHabitaciones];
	habitacionesDobles = new Doble[numMaxHabitaciones];
	habitacionesMatrimonio = new Matrimonio[numMaxHabitaciones];

}