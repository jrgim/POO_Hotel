#pragma once
#include "Habitacion.h"
class Doble : public Habitacion
{
public:
	Doble();
	Doble(bool, int, int);
	void ActualizarPrecio(float);
	void numerar(int);
};

