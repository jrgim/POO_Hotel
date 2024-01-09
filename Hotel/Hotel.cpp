#include "Hotel.h"
Hotel::Hotel() {
	nombreHotel = "NH Zaragoza";
	habitacionesSimples = new Simple[numMaxHabitaciones];
	habitacionesDobles = new Doble[numMaxHabitaciones];
	habitacionesMatrimonio = new Matrimonio[numMaxHabitaciones];
	//Clientes = new Cliente[maxNumClientes];
	Reservas = new Reserva[maxNumReservas];
	opcionSeleccionada = 0;
	numDeReservas = 0;
}

void Hotel::listaHabitaciones() {
	cout << "~~~~~~~~~~~~~~Habitaciones simples:~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < numMaxHabitaciones; i++) {
		cout << "La habitacion numero: " << i << habitacionesSimples[i];
	}
	cout << "\n\n\n~~~~~~~~~~~~~~Habitaciones dobles:~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < numMaxHabitaciones; i++) {
		cout << "La habitacion numero: " << i + 100 << habitacionesDobles[i];
	}
	cout << "\n\n\n~~~~~~~~~~~~~~Habitaciones de Matrimonio:~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < numMaxHabitaciones; i++) {
		cout << "La habitacion numero: " << i + 200 << habitacionesMatrimonio[i];
	}
}
void Hotel::consultarPrecioHabitacion() {
	int seleccion = 0;
	while (seleccion != 1 && seleccion != 2 && seleccion != 3) {
		cout << "Tipo de habitacion: 1. Simple, 2. Doble, 3. Matrimonio: ";
		cin >> seleccion;
	}
	switch (seleccion)
	{
	case 1:
		habitacionesSimples[0].ObtenerPrecioHabitacion();//devuelve un numero, si no lo uso cambiarlo
		break;
	case 2:
		habitacionesDobles[0].ObtenerPrecioHabitacion();//devuelve un numero, si no lo uso cambiarlo
		break;
	case 3:
		habitacionesMatrimonio[0].ObtenerPrecioHabitacion();//devuelve un numero, si no lo uso cambiarlo
		break;
	}
}
int Hotel::ObtenerHabitacionLibre(int tipoHabitacion) {//tipo de habitacion: 0: H.Simple, 1: H.Doble, 2: H.Matrimonio
	if (tipoHabitacion == 0) {
		for (int i = 0; i < numMaxHabitaciones; i++) {
			if (habitacionesSimples[i].Disponibilidad() == true) {
				return i;
			}
		}
	}
	else if (tipoHabitacion == 1) {
		for (int i = 0; i < numMaxHabitaciones; i++) {
			if (habitacionesDobles[i].Disponibilidad() == true) {
				return i;
			}
		}
	}
	else if (tipoHabitacion == 2) {
		for (int i = 0; i < numMaxHabitaciones; i++) {
			if (habitacionesMatrimonio[i].Disponibilidad() == true) {
				return i;
			}
		}
	}
	return -1;
}

void Hotel::reservarHabitacion() {
	int numHabitacion = 0;
	cin >> Reservas[numDeReservas];
	numHabitacion = ObtenerHabitacionLibre(Reservas[numDeReservas].numTipoHabitacion());
	if (numHabitacion == -1) {
		cout << "No se ha encontrado una habitacion libre" << endl;
	}
	else {
		Reservas[numDeReservas].anadirNumHabitacion(numHabitacion);
		switch (Reservas[numDeReservas].numTipoHabitacion()) {
		case 0:
			habitacionesSimples[numHabitacion].llenarHabitacion(Reservas[numDeReservas].numHuespedes());
			break;
		case 1:
			habitacionesDobles[numHabitacion].llenarHabitacion(Reservas[numDeReservas].numHuespedes());
			break;
		case 2:
			habitacionesMatrimonio[numHabitacion].llenarHabitacion(Reservas[numDeReservas].numHuespedes());
			break;
		}
		numDeReservas++;
	}
}