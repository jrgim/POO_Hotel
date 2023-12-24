#pragma once
#include "Habitacion.h"
class Matrimonio : public Habitacion
{
private:
	float Precio;
public:
	Matrimonio();
	Matrimonio(bool, int, int);
	void ActualizarPrecio(float);
};

