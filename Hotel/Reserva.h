#pragma once
#include "Habitacion.h"
#include "Cliente.h"
#include "Hotel.h"
#include<iostream>
using namespace std;

class Reserva
{
private:
	int numClientesHabitacion;
	string tipoHabitacion;
	Cliente* ClientesReserva;
	int numNoches;
	string fechaEntrada;
	int numHabitacion;// se obtiene mediante el metodo de la clase Habitacion
public:
	Reserva();
	Reserva(int, string, int, int);
	float precioTotal();
	void anadirClientes(Cliente, int);
	friend istream& operator>>(istream&, Reserva&);
};

