/*#include "Reserva.h"
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
	int numPersonasReserva, tipoHabitacion, auxNumPersonas, tipoCliente;//cambiar 5
	Cliente cliente;
	cout << "Introduce el numero de noches: ";
	cin >> reserva.numNoches;
	cout << "\n Introduce el numero de personas a hospedar: ";
	cin >> numPersonasReserva;
	while (numPersonasReserva >= 3) {
		cout << "El numero maximo de personas por habitacio es de 2 personas." << endl;
		cout << "Introduce el numero de personas a hospedar : ";
		cin >> numPersonasReserva;
	}

	cout << "Introduce el tipo de habitacion: 0: H.Simple, 1: H.Doble, 2: H.Matrimonio" << endl;
	cin >> tipoHabitacion;
	while (tipoHabitacion > 2) {
		cout << "Numero introducido erroneo. Introduce el tipo de habitacion: 0: H.Simple, 1: H.Doble, 2: H.Matrimonio" << endl;
		cin >> tipoHabitacion;
	}

	cout << "Seleccione tipo de cliente: 0. Habitual, 1. Esporadico: ";
	cin >> tipoCliente;
	while (tipoCliente > 1) {
		cout << "Tipo de cliente seleccionado erroneo.\nSeleccione tipo de cliente: 0. Habitual, 1. Esporadico: ";
		cin >> tipoCliente;
	}
	//cambiar esto. solo quiero poner los tipos de habitaciones por numeros
	//quiero guardar los clientes en el hotel? o en la clase reserva?
	/*
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
	}*//*

	return is;
}*/