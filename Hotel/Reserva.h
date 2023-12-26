#pragma once
#include "Habitacion.h"
#include "Cliente.h"
#include "Hotel.h"
#include<iostream>
using namespace std;

class Reserva
{
private:
	string tipoHabitacion;
	Cliente* Clientes;
	int numNoches;
	string fechaEntrada;
	int numHabitacion;// se obtiene mediante el metodo de la clase Habitacion
public:
	Reserva();
	Reserva(int, string, int);
	float precioTotal();
};

