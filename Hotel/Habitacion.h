#pragma once
#include <iostream>;
using namespace std;
class Habitacion
{
	//Hacer array tipos de  habitaciones, no se si un array para todos o uno de cada
private:
	string TipoHabitacion;//creo que no hace falta
	float Precio;
	bool disponible;
	int huespedes;
public:
	Habitacion();
	float ObtenerPrecioHabitacion();//las voy a intentar hacer virtual puro
	bool Disponibilidad();
	int ObtenerHabitacionLibre();//intenta devolver el numero de la habitacion libre o un objeto de tipo habitacion
	float ActualizarPrecio(float);
};

