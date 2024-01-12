#pragma once
#include <iostream>
using namespace std;
class Habitacion
{
protected:
	float Precio;
	bool disponible;
	int huespedes;
	int numHabitacion;
public:
	Habitacion();//no se si hay que  Shacer el constructor
	float const ObtenerPrecioHabitacion();
	bool Disponibilidad();//comprueba si la habitacion esta libre
	virtual void ActualizarPrecio(float) = 0;
	friend istream& operator>>(istream&, Habitacion&);
	friend ostream& operator<<(ostream&, const Habitacion&);
	void llenarHabitacion(int);
	void listaHabitaciones();//poner const
	virtual void numerar(int);
};

