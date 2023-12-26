#pragma once
#include <iostream>;
using namespace std;
class Habitacion
{
	//Hacer array tipos de  habitaciones, no se si un array para todos o uno de cada
protected:
	float Precio;
	bool disponible;
	int huespedes;
	int numHabitacion;
public:
	Habitacion();//no se si hay que hacer el constructor
	float const ObtenerPrecioHabitacion();
	bool Disponibilidad();//comprueba si la habitacion esta libre
	virtual void ActualizarPrecio(float);// const = 0;
};

