#include "Hotel.h"
Hotel::Hotel() {
	habitacionesSimples = new Simple[numMaxHabitaciones];
	habitacionesDobles = new Doble[numMaxHabitaciones];
	habitacionesMatrimonio = new Matrimonio[numMaxHabitaciones];
	Clientes = new Cliente[30];

}
int Hotel::ObtenerHabitacionLibre(int tipoHabitacion) {
	switch (tipoHabitacion)
	{
	case 0:
		for (int i = 0; i < numMaxHabitaciones; i++) {
			if (habitacionesSimples[i].Disponibilidad) {
				return habitacionesSimples[i].numHabitacion;
			}
		}
	default:
		cout << "Tipo de habitacion introduccido erroneo. 0: H.Simple, 1: H.Doble, 2: H.Matrimonio" << endl;
		break;
	}
}