#pragma once
#include<iostream>
using namespace std;

#include "Cliente.h"
#include "Habitacion.h"
#include "Reserva.h"
#include "Simple.h"
#include "Doble.h"
#include "Matrimonio.h"

#define numMaxHabitaciones 20
#define maxNumClientes 100
#define maxNumReservas 200

class Hotel
{
private:
	string nombreHotel;
	Simple* habitacionesSimples;
	Doble* habitacionesDobles;
	Matrimonio* habitacionesMatrimonio;
	Reserva* Reservas;
	//Cliente* Clientes;
	int opcionSeleccionada;
	int numDeReservas;
public:
	Hotel();//constructor por defecto, creo que pondre aqui el nombre
	void consultarPrecioHabitacion();
	//float consultarDescuento(Cliente);
	//void modificarDescuento(Cliente, int);
	//void cambioPrecioHabitacion(Cliente, Habitacion, Reserva);
	//float precioTotal(Cliente, Habitacion, Reserva);
	void reservarHabitacion();
	//bool eliminarReserva(Reserva);
	//float calcularGanancias(int);
	void listaHabitaciones();
	//Guardar datos
	//Funciones adicionales
	int ObtenerHabitacionLibre(int);//intenta devolver el numero de la habitacion libre



	/*
	* Como cargar estado del hotel y guardar en el hotel
	*/
};

