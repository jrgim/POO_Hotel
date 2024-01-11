#pragma once
#include<iostream>
#include<fstream>
#include<Windows.h>
using namespace std;

#include "Cliente.h"
#include "Habitacion.h"
#include "Reserva.h"
#include "Simple.h"
#include "Doble.h"
#include "Matrimonio.h"
#include "Almacenamiento.h"

#define numMaxHabitaciones 21
#define maxNumClientes 100
#define maxNumReservas 200
#define color SetConsoleTextAttribute

class Hotel
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
private:
	string nombreHotel;
	Simple* habitacionesSimples;
	Doble* habitacionesDobles;
	Matrimonio* habitacionesMatrimonio;
	Reserva* Reservas;
	Cliente* Clientes;
	int numClientes;
	int opcionSeleccionada;
	int numDeReservas;
public:
	Hotel();
	void numerarHabitaciones();
	void consultarPrecioHabitacion();
	void cambiarPrecioHabitacion();//void cambioPrecioHabitacion(Cliente, Habitacion, Reserva);
	int consultarDescuento(Cliente&);
	void modificarDescuento();//¿Se modifica a uno o a todos?  SIN TERMINAR
	//float precioTotal(Cliente, Habitacion, Reserva);
	void reservarHabitacion();
	//bool eliminarReserva(Reserva);
	//float calcularGanancias(int);
	void listaHabitaciones();
	int ObtenerHabitacionLibre(int);//intenta devolver el numero de la habitacion libre
	Cliente buscarCliente(string);
	void nuevoCliente(Cliente);
	void guardar();//TODO: Solo carga habitaciones simples y mal. Cambiar sobrecarga
	void cargar();
	/*
	* Como cargar estado del hotel y guardar en el hotel
	*/
};

