#pragma once
#include<stdexcept>
#include<iostream>
using namespace std;	

class ExcepcionNumero
{
public:
	string what() {
		return "No se ha introducido un numero. Seleccione una opcion: ";
	}
};