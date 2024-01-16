#pragma once
#include "Habitacion.h"
class Simple : public Habitacion
{
public:
	Simple();
	Simple(bool, int, int);
	void ActualizarPrecio(float);
	float ObtenerPrecioHabitacion()const;
};

