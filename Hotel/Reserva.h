#pragma once
#include "Habitacion.h"
#include "Cliente.h"
#include "ClienteEsporadico.h"
#include "ClienteHabitual.h"
#include<iostream>
using namespace std;

class Reserva
{
private:
	int numClientesHabitacion;
	int tipoHabitacion; //0: H.Simple, 1: H.Doble, 2: H.Matrimonio
	Cliente* ClientesReserva;
	int numNoches;
	string fechaEntrada;
	int numHabitacion;// se obtiene mediante el metodo de la clase Habitacion
public:
	Reserva();
	Reserva(int, string, int, int, int);
	float precioTotal();
	int numTipoHabitacion();//chapuza
	int numHuespedes();
	void anadirClientes(Cliente, int);
	void anadirNumHabitacion(int);
	Cliente Clientes(int);
	friend istream& operator>>(istream&, Reserva&);
};

