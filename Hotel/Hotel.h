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

class Hotel
{
private:
	string nombreHotel;
	Simple* habitacionesSimples;
	Doble* habitacionesDobles;
	Matrimonio* habitacionesMatrimonio;
	Cliente* Clientes;
public:
	Hotel();//constructor por defecto, creo que pondre aqui el nombre
	float consultarPrecioHabitacion(string);
	float consultarDescuento(Cliente);
	void modificarDescuento(Cliente, int);
	void cambioPrecioHabitacion(Cliente, Habitacion, Reserva);//pq paso cliente?
	float precioTotal(Cliente, Habitacion, Reserva);
	Reserva reservarHabitacion(Cliente, Habitacion, int);
	bool eliminarReserva(Reserva);
	float calcularGanancias(int);
	void listaHabitaciones(Habitacion);
	void modificarPrecioHabitacion(string, int);//creo qeu estan repetidas

	//Funciones adicionales
	int ObtenerHabitacionLibre(int);//intenta devolver el numero de la habitacion libre



	/*
	* Como cargar estado del hotel y guardar en el hotel
	*/
};

