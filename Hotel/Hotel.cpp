#include "Hotel.h"
Hotel::Hotel() {
	nombreHotel = "NH Zaragoza";
	habitacionesSimples = new Simple[numMaxHabitaciones];
	habitacionesDobles = new Doble[numMaxHabitaciones];
	habitacionesMatrimonio = new Matrimonio[numMaxHabitaciones];
	Clientes = new Cliente[maxNumClientes];
	Reservas = new Reserva[maxNumReservas];
	numClientes = 0;
	opcionSeleccionada = 0;
	numDeReservas = 0;
	numerarHabitaciones();
}
void Hotel::numerarHabitaciones() {
	for (int i = 0; i < numMaxHabitaciones; i++) {
		habitacionesSimples[i].numerar(i);
		habitacionesDobles[i].numerar(i + 100);
		habitacionesMatrimonio[i].numerar(i + 200);
	}
}
void Hotel::listaHabitaciones() {
	cout << "~~~~~~~~~~~~~~Habitaciones simples:~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < numMaxHabitaciones; i++) {
		cout << "La habitacion numero: " << i;
		habitacionesSimples[i].listaHabitaciones();
	}
	cout << "\n\n\n~~~~~~~~~~~~~~Habitaciones dobles:~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < numMaxHabitaciones; i++) {
		cout << "La habitacion numero: " << i + 100;
		habitacionesDobles[i].listaHabitaciones();
	}
	cout << "\n\n\n~~~~~~~~~~~~~~Habitaciones de Matrimonio:~~~~~~~~~~~~~~" << endl;
	for (int i = 0; i < numMaxHabitaciones; i++) {
		cout << "La habitacion numero: " << i + 200;
		habitacionesMatrimonio[i].listaHabitaciones();
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
	Reservas[numDeReservas].nuevaReserva();
	numHabitacion = ObtenerHabitacionLibre(Reservas[numDeReservas].numTipoHabitacion());
	if (numHabitacion == -1) {
		cout << "No se ha encontrado una habitacion libre" << endl;
	}
	else {
		Reservas[numDeReservas].anadirNumHabitacion(numHabitacion);
		switch (Reservas[numDeReservas].numTipoHabitacion()) {
		case 0:
			habitacionesSimples[numHabitacion].llenarHabitacion(Reservas[numDeReservas].numHuespedes());
			nuevoCliente(Reservas[numDeReservas].Clientes(0));
			break;
		case 1:
			habitacionesDobles[numHabitacion].llenarHabitacion(Reservas[numDeReservas].numHuespedes());
			nuevoCliente(Reservas[numDeReservas].Clientes(0));
			nuevoCliente(Reservas[numDeReservas].Clientes(1));
			break;
		case 2:
			habitacionesMatrimonio[numHabitacion].llenarHabitacion(Reservas[numDeReservas].numHuespedes());
			nuevoCliente(Reservas[numDeReservas].Clientes(0));
			nuevoCliente(Reservas[numDeReservas].Clientes(1));
			break;
		}
		numDeReservas++;
	}
}
int Hotel::consultarDescuento(Cliente& const cliente) {
	return cliente.ObtenerDescuento();
}

void Hotel::nuevoCliente(Cliente client) {
	Clientes[numClientes] = client;
	numClientes++;
}

Cliente Hotel::buscarCliente(string nombreABuscar) {//TODO: corregir
	int i = 0;
	while (Clientes[i].ComprobarNombre(nombreABuscar) == false) {
		i++;
		if (i == maxNumClientes) {
			cout << "No se ha encontrado el cliente. Introduzca otro nombre: " << endl;
			cin >> nombreABuscar;
			i = 0;
		}
	}
	return Clientes[i];

	/*OTRA FORMA MAL
	for (int i = 0; i < maxNumClientes; i++)
		if(Clientes[i].ComprobarNombre(nombreABuscar)){
			return Clientes[i];
		}
		else {
			cout << "No se ha encontrado el cliente. Introduzca otro nombre: " << endl;
			cin >> nombreABuscar;
		}*/

}
void Hotel::guardar() {
	//Guarda Habitaciones
	Almacenamiento<Simple>almacenamientoHabitacionesS("HabitacionesSimples.txt");
	almacenamientoHabitacionesS.guardar(habitacionesSimples, numMaxHabitaciones);
	Almacenamiento<Doble>almacenamientoHabitacionesD("HabitacionesDobles.txt");
	almacenamientoHabitacionesD.guardar(habitacionesDobles, numMaxHabitaciones);
	Almacenamiento<Matrimonio>almacenamientoHabitacionesM("HabitacionesMatrimonio.txt");
	almacenamientoHabitacionesM.guardar(habitacionesMatrimonio, numMaxHabitaciones);
	//Guarda Reservas
	Almacenamiento<Reserva>almacenamientoReservas("Reservas.txt");
	almacenamientoReservas.guardar(Reservas, maxNumReservas);
	//Guarda Clientes
	Almacenamiento<Cliente>almacenamientoClientes("Clientes.txt");
	almacenamientoClientes.guardar(Clientes, maxNumClientes);
}
void Hotel::cargar() {
	//Carga Habitaciones
	Almacenamiento<Simple>almacenamientoHabitacionesS("HabitacionesSimples.txt");
	almacenamientoHabitacionesS.cargar(habitacionesSimples, numMaxHabitaciones);
	Almacenamiento<Doble>almacenamientoHabitacionesD("HabitacionesDobles.txt");
	almacenamientoHabitacionesD.cargar(habitacionesDobles, numMaxHabitaciones);
	Almacenamiento<Matrimonio>almacenamientoHabitacionesM("HabitacionesMatrimonio.txt");
	almacenamientoHabitacionesM.cargar(habitacionesMatrimonio, numMaxHabitaciones);
	//Carga Reservas
	Almacenamiento<Reserva>almacenamientoReservas("Reservas.txt");
	almacenamientoReservas.cargar(Reservas, maxNumReservas);
	//Carga Clientes
	Almacenamiento<Cliente>almacenamientoClientes("Clientes.txt");
	almacenamientoClientes.cargar(Clientes, maxNumClientes);
}
void Hotel::modificarDescuento() {
	int nuevoDescuento=0;
	cout << "Introduce el nuevo descuento para los clientes habituales: ";
	cin >> nuevoDescuento;
	//Clientes.nuevo
}//TODO: terminar



void Hotel::cambiarPrecioHabitacion() {//hacer while num erroneo
	int seleccion = -1;
	float nPrecioSimple = 0, nPrecioDoble = 0, nPrecioMatrimonio = 0;
	color(hConsole, 10);
	cout << "Introduzca el tipo de Habitacion que desea cambiar el precio: 0. Simple, 1. Doble, 2. Matrimonio: ";
	cin >> seleccion;
	switch (seleccion)
	{
	case 0:
		color(hConsole, 1);
		cout << "\nIntroduce el nuevo precio para las habitaciones Simples: ";
		cin >> nPrecioSimple;
		for (int i = 0; i < numMaxHabitaciones; i++) {
			habitacionesSimples[i].ActualizarPrecio(nPrecioSimple);
		}
		break;
	case 1:
		color(hConsole, 2);
		cout << "\nIntroduce el nuevo precio para las habitaciones Dobles: ";
		cin >> nPrecioDoble;
		for (int i = 0; i < numMaxHabitaciones; i++) {
			habitacionesDobles[i].ActualizarPrecio(nPrecioDoble);
		}
		break;
	case 2:
		color(hConsole, 3);
		cout << "\nIntroduce el nuevo precio para las habitaciones de Matrimonio: ";
		cin >> nPrecioMatrimonio;
		for (int i = 0; i < numMaxHabitaciones; i++) {
			habitacionesMatrimonio[i].ActualizarPrecio(nPrecioMatrimonio);
		}
		break;
	default:
		cout << "Numero introducido erroneo. Introduzca el tipo de Habitacion: 0. Simple, 1. Doble, 2. Matrimonio" << endl;
		cin >> seleccion;
		break;
	}
	cout << "\nPrecio actualizado." << endl;
}