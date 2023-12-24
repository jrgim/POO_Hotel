#pragma once
#include "Habitacion.h"
class Simple : public Habitacion
{
private:
	float Precio;
public:
	Simple();
	Simple(bool, int);
};

