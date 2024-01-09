#pragma once
#include "Habitacion.h"
class Matrimonio : public Habitacion
{
public:
	Matrimonio();
	Matrimonio(bool, int, int);
	void ActualizarPrecio(float);
};

