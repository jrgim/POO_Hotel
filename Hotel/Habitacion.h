#pragma once
#include <iostream>;
using namespace std;
class Habitacion
{
	//Hacer array tipos de  habitaciones, no se si un array para todos o uno de cada
protected:
	bool disponible;
	int huespedes;
public:
	Habitacion();//no se si hay que hacer el constructor
	float ObtenerPrecioHabitacion();//las voy a intentar hacer virtual puro
	virtual bool Disponibilidad(const Habitacion&);
	int ObtenerHabitacionLibre();//intenta devolver el numero de la habitacion libre o un objeto de tipo habitacion
	float ActualizarPrecio(float);
};

