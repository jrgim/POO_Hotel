#pragma once
#include "Cliente.h"
class ClienteEsporadico : public Cliente
{
	ClienteEsporadico();
	ClienteEsporadico(string, string);
	int ObtenerDescuento() const;
};

