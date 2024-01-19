#pragma once
#include <iostream>
using namespace std;
class ExcepcionNombre {
public:
	void what() {
		cout << "Error: No se ha encontrado el cliente." << endl;
	}
};

