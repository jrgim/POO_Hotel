#pragma once
#include "Habitacion.h"
#include "Cliente.h"
#include<iostream>
using namespace std;

class Reserva
{
private:
	Habitacion *TipoHabitacion;//creo que esta mal
	Cliente* cliente;
	int numNoches;
	string fechaEntrada;
	int numHabitacion;// se obtiene mediante el metodo de la clase Habitacion
public:
	Reserva();
	Reserva(int, string, int);
	float precioTotal();
};

