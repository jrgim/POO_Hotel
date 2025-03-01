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
	int dia;
	int mes;
	int anio;
	int numHabitacion;// se obtiene mediante el metodo de la clase Habitacion
public:
	Reserva();
	Reserva(int, int, int, int, int, int, int);
	int numTipoHabitacion();//chapuza
	int numHuespedes();
	void anadirClientes(Cliente, int);
	void anadirNumHabitacion(int);
	int obtenerNumHabitacion();//chapuza
	int obtenerNumNoches();//chapuza
	void nuevaReserva();
	int mesReserva();
	bool buscarClientes(Cliente&);
	Cliente Clientes(int);
	friend istream& operator>>(istream&, Reserva&);
	friend ostream& operator<<(ostream&, const Reserva&);
};

