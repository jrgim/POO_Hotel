#pragma once
#include "Cliente.h"
class ClienteEsporadico : public Cliente
{
public:
	ClienteEsporadico();
	ClienteEsporadico(string, string);
	int ObtenerDescuento() const;
};

