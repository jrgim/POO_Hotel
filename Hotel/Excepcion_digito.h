#pragma once
#include <stdexcept>
using namespace std;
class Excepcion_digito : public invalid_argument {
public:
	Excepcion_digito() : invalid_argument("Error: No se ha introducido un digito.") {}
};

