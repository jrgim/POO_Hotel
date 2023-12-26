#include "Reserva.h"
Reserva::Reserva(){
    ClientesReserva = new Cliente[numClientesHabitacion];
    numNoches=0;
    fechaEntrada = "10/12/2023";
    numHabitacion= 0;
}

Reserva::Reserva(int numNoches, string fechaEntrada, int numHabitacion, int numClientesHabitacion){
    this->numNoches = numNoches;
    this->fechaEntrada = fechaEntrada;
    this->numHabitacion=numHabitacion;
    this->numClientesHabitacion = numClientesHabitacion;
}
void Reserva::anadirClientes(Cliente cliente, int indice) {
    ClientesReserva[indice] = cliente;
}
istream& operator>>(istream& is, Reserva& reserva) {
	int numPersonasReserva, tipoHabitacion[5], auxNumPersonas, tipoCliente;//cambiar 5
	Cliente cliente;
	cout << "Introduce el numero de noches: ";
	cin >> reserva.numNoches;
	cout << "\n Introduce el numero de personas a hospedar: ";
	cin >> numPersonasReserva;
	auxNumPersonas = numPersonasReserva;
	for (int i =0; i<auxNumPersonas;i++){
		cout << "Introduce el tipo de habitacion: 0: H.Simple, 1: H.Doble, 2: H.Matrimonio" << endl;
		cin >> tipoHabitacion[i];
		switch (tipoHabitacion[i])
		{
		case 0:
			numPersonasReserva--;
			break;
		case 1:
			numPersonasReserva = numPersonasReserva - 2;
			break;
		case 2:
			numPersonasReserva = numPersonasReserva - 2;
			break;
		default:
			cout << "Numero introducido erroneo. Introduce el tipo de habitacion: 0: H.Simple, 1: H.Doble, 2: H.Matrimonio" << endl;
			break;
		}
	}
	cout << "Seleccione tipo de cliente: 0. Habitual, 1. Esporadico: ";
	cin >> tipoCliente;
	for (int i = 0; i < auxNumPersonas; i++) {
		cout << "Seleccione tipo de cliente: 0. Habitual, 1. Esporadico: ";
		cin >> tipoCliente;
		if (tipoCliente == 0) {
			cout << "Cliente " << i << ": ";
			cin >> cliente;
			ClienteHabitual Habitual;
			cin >> Habitual;
			reserva.anadirClientes(Habitual, i);
		}
		else if (tipoCliente == 1) {
			cout << "Cliente " << i << ": ";
			cin >> cliente;
			ClienteEsporadico Esporadico;
			reserva.anadirClientes(Esporadico, i);
		}
		else cout << "Tipo de cliente incorrecto"<<endl;
	}

	return is;
}