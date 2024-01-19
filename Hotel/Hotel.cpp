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
		habitacionesDobles[i].numerar(i);
		habitacionesMatrimonio[i].numerar(i);
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
		//Reservas[numDeReservas].anadirNumHabitacion(numHabitacion);
		switch (Reservas[numDeReservas].numTipoHabitacion()) {
		case 0:
			Reservas[numDeReservas].anadirNumHabitacion(numHabitacion);
			habitacionesSimples[numHabitacion].llenarHabitacion(Reservas[numDeReservas].numHuespedes());
			nuevoCliente(Reservas[numDeReservas].Clientes(0));
			break;
		case 1:
			Reservas[numDeReservas].anadirNumHabitacion(numHabitacion+100);
			habitacionesDobles[numHabitacion].llenarHabitacion(Reservas[numDeReservas].numHuespedes());
			nuevoCliente(Reservas[numDeReservas].Clientes(0));
			
			break;
		case 2:
			Reservas[numDeReservas].anadirNumHabitacion(numHabitacion+200);
			habitacionesMatrimonio[numHabitacion].llenarHabitacion(Reservas[numDeReservas].numHuespedes());
			nuevoCliente(Reservas[numDeReservas].Clientes(0));
			
			break;
		}
		cout <<"Habitacion asignada n: "<<Reservas[numDeReservas].obtenerNumHabitacion()<<endl;
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

Cliente Hotel::buscarCliente() {//TODO: corregir
	int i = 0;
	string nombreABuscar;
	cout << "Nombre del cliente a buscar: ";
	cin >> nombreABuscar;
	while (Clientes[i].ComprobarNombre(nombreABuscar) == false) {
		i++;
		if (i == maxNumClientes) {
			cout << "No se ha encontrado el cliente. Introduzca otro nombre: " << endl;
			cin >> nombreABuscar;
			i = 0;
		}
	}
	return Clientes[i];
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
	bool aux[maxNumClientes];
	cout << "Introduce el nuevo descuento para los clientes habituales anadidos al hotel: ";
	cin >> nuevoDescuento;
	for (int i = 0; i < maxNumClientes; i++) {
		if (Clientes[i].ObtenerTipoCliente() == 0) {
			aux[i]=Clientes[i].nuevoDescuento(nuevoDescuento);
		}
	}
	for (int j = 0; j < maxNumClientes; j++) {
		if (aux[j] == false) {
			cout << "Descuento NO modificado."<<endl;
		}
	}
	cout << "Descuento modificado correctamente."<<endl;
}



void Hotel::cambiarPrecioHabitacion() {
	int seleccion = -1;
	float nPrecioSimple = 0, nPrecioDoble = 0, nPrecioMatrimonio = 0;
	color(hConsole, 10);
	cout << "Introduzca el tipo de Habitacion que desea cambiar el precio: 0. Simple, 1. Doble, 2. Matrimonio: ";
	while (seleccion != 0 && seleccion != 1 && seleccion != 2) {
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
			color(hConsole, 4);
			cout << "\nNumero introducido erroneo. Introduzca el tipo de Habitacion: 0. Simple, 1. Doble, 2. Matrimonio: ";
			break;
		}
	}
	cout << "\nPrecio actualizado." << endl;
}

void Hotel::precioTotalRecepcion(Cliente& cliente) {
	int numHabitacion = -10, descuento=0;
	float precio = 0, precioTotal = 0;
	for (int i = 0; i < maxNumReservas; i++) {
		if (Reservas[i].buscarClientes(cliente)) {
			numHabitacion = Reservas[i].obtenerNumHabitacion();
			if (numHabitacion >= 0 && numHabitacion < 100) {
				precio = habitacionesSimples[i].ObtenerPrecioHabitacion();
				cout << "El precio de la habitacion X noche es de: " << precio << "Euros." << endl;
				precio = (precio * Reservas[i].obtenerNumNoches());
				precioTotal = cliente.aplicarDescuento(precio);
				cout << "El precio total es de: " << precioTotal << " Euros." << endl;
			}
			else if (numHabitacion >= 100 && numHabitacion < 200) {
				precio = habitacionesDobles[i].ObtenerPrecioHabitacion();
				cout << "El precio de la habitacion X noche es de: " << precio << "Euros." << endl;
				precio = (precio * Reservas[i].obtenerNumNoches());
				precioTotal = cliente.aplicarDescuento(precio);
				cout << "El precio total es de: " << precioTotal << " Euros." << endl;
			}
			else if (numHabitacion >= 200 && numHabitacion < 300) {
				precio = habitacionesMatrimonio[i].ObtenerPrecioHabitacion();
				cout << "El precio de la habitacion X noche es de: " << precio << "Euros." << endl;
				precio = (precio * Reservas[i].obtenerNumNoches());
				precioTotal = cliente.aplicarDescuento(precio);
				cout << "El precio total es de: " << precioTotal << " Euros." << endl;
			}
		}
	}
}
float Hotel::precioTotal(Cliente& cliente) {
	int numHabitacion = -10, descuento = 0;
	float precio = 0, precioTotal = 0;
	for (int i = 0; i < maxNumReservas; i++) {
		if (Reservas[i].buscarClientes(cliente)) {
			numHabitacion = Reservas[i].obtenerNumHabitacion();
			if (numHabitacion >= 0 && numHabitacion < 100) {
				precio = habitacionesSimples[i].ObtenerPrecioHabitacion();
				precio = (precio * Reservas[i].obtenerNumNoches());
				precioTotal = cliente.aplicarDescuento(precio);
				return precioTotal;
			}
			else if (numHabitacion >= 100 && numHabitacion < 200) {
				precio = habitacionesDobles[i].ObtenerPrecioHabitacion();
				precio = (precio * Reservas[i].obtenerNumNoches());
				precioTotal = cliente.aplicarDescuento(precio);
				return precioTotal;
			}
			else if (numHabitacion >= 200 && numHabitacion < 300) {
				precio = habitacionesMatrimonio[i].ObtenerPrecioHabitacion();
				precio = (precio * Reservas[i].obtenerNumNoches());
				precioTotal = cliente.aplicarDescuento(precio);
				return precioTotal;
			}
		}
	}
}
Reserva Hotel::buscarReserva(int numeroHabitacion) {
	for (int i = 0; i < maxNumReservas; i++) {
		if (Reservas[i].obtenerNumHabitacion() == numeroHabitacion) {
			return Reservas[i];
		}
		else if( i == 1-maxNumReservas) {
			cout << "No se ha encontrado la reserva."<<endl;
		}
	}
}

bool Hotel::eliminarReserva() {
	int numeroHabitacion;
	cout << "Introduce el numero de habitacion: ";
	cin >> numeroHabitacion;
	for (int i = 0; i < maxNumReservas; i++) {
		if (Reservas[i].obtenerNumHabitacion() == numeroHabitacion) {
			for (int j = i; j < maxNumReservas-1; j++) {
				Reservas[j] = Reservas[j + 1];
			}

			if (numeroHabitacion >= 0 && numeroHabitacion < 100) {
				habitacionesSimples[numeroHabitacion].vaciarHabitacion();
			}
			else if (numeroHabitacion >= 100 && numeroHabitacion < 200) {
				habitacionesDobles[numeroHabitacion].vaciarHabitacion();
			}
			else if (numeroHabitacion >= 200 && numeroHabitacion < 300) {
				habitacionesMatrimonio[numeroHabitacion].vaciarHabitacion();
			}
			for (int j = i; j < maxNumClientes-1; j++) {
				Clientes[j] = Clientes[j + 1];
			}
			cout << "\nSe ha eliminado la reserva." << endl;
			return true;
		}
		else {
			cout << "\nNo se ha encontrado la reserva." << endl;
			return false;
		}
	}
}
void Hotel::calcularGanancias() {
	int mesABuscar;
	float ganancias=0.0;
	cout << "Introduce el numero de mes a buscar con el formato (Enero: 01): ";
	cin >> mesABuscar;
	for (int i = 0; i < maxNumReservas; i++) {
		if (Reservas[i].mesReserva() == mesABuscar) {
			Cliente aux = Reservas[i].Clientes(0);
			ganancias = ganancias + precioTotal(aux);
		}
	}
	cout << "\nLas ganancias del mes " << mesABuscar << " son de: " << ganancias << " Euros." << endl;
}