#include "Reserva.h"
Reserva::Reserva(){
    ClientesReserva = new Cliente[numClientesHabitacion];//PUEDE FALLAR
    numNoches=0;
    fechaEntrada = "10/12/2023";
    numHabitacion= 0;
	numClientesHabitacion = 0;
}

Reserva::Reserva(int numNoches, string fechaEntrada, int numHabitacion, int numClientesHabitacion, int tipoHabitacion){
    this->numNoches = numNoches;
    this->fechaEntrada = fechaEntrada;
    this->numHabitacion=numHabitacion;
    this->numClientesHabitacion = numClientesHabitacion;
	this->tipoHabitacion = tipoHabitacion;
}
void Reserva::anadirClientes(Cliente cliente, int indice) {
    ClientesReserva[indice] = cliente;
}
istream& operator>>(istream& is, Reserva& reserva) {
	int tipoCliente;
	Cliente cliente;
	cout << "Introduce el numero de noches: ";
	is >> reserva.numNoches;
	cout << "\nIntroduce la fecha de entrada: ";
	is >> reserva.fechaEntrada;
	cout << "\n Introduce el numero de personas a hospedar: ";
	is >> reserva.numClientesHabitacion;
	while (reserva.numClientesHabitacion >= 3) {
		cout << "El numero maximo de personas por habitacion es de 2 personas." << endl;
		cout << "Introduce el numero de personas a hospedar : ";
		is >> reserva.numClientesHabitacion;
	}

	cout << "Introduce el tipo de habitacion: 0: H.Simple, 1: H.Doble, 2: H.Matrimonio" << endl;
	is >> reserva.tipoHabitacion;

	if (reserva.numClientesHabitacion == 1) {//Opcion solo 1 Huesped
		while (reserva.tipoHabitacion > 2) {
			cout << "Numero introducido erroneo. Introduce el tipo de habitacion: 0: H.Simple, 1: H.Doble, 2: H.Matrimonio" << endl;
			is >> reserva.tipoHabitacion;
		}
	}
	if (reserva.numClientesHabitacion == 2) {
		if (reserva.tipoHabitacion == 1) {
			cout << "Habitacion pequeña para 2 personas. Introduce el tipo de habitacion mas grande: 1: H.Doble, 2: H.Matrimonio";
			is >> reserva.tipoHabitacion;
		}
		while (reserva.tipoHabitacion > 2) {
			cout << "Numero introducido erroneo. Introduce el tipo de habitacion: 0: H.Simple, 1: H.Doble, 2: H.Matrimonio" << endl;
			is >> reserva.tipoHabitacion;
		}
	}
	
	
	cout << "Seleccione tipo de cliente: 0. Habitual, 1. Esporadico: ";
	cin >> tipoCliente;
	while (tipoCliente > 1) {//Hacer negativo
		cout << "Tipo de cliente seleccionado erroneo.\nSeleccione tipo de cliente: 0. Habitual, 1. Esporadico: ";
		cin >> tipoCliente;
	}
	//cambiar esto. solo quiero poner los tipos de habitaciones por numeros
	//quiero guardar los clientes en el hotel? o en la clase reserva?
	for (int i = 0; i < reserva.numClientesHabitacion; i++) {
		cout << "Seleccione tipo de cliente: 0. Habitual, 1. Esporadico: ";
		cin >> tipoCliente;
		if (tipoCliente == 0) {
			cout << "Cliente " << i << ": ";
			//cin >> cliente;
			ClienteHabitual Habitual;
			cin >> Habitual;
			reserva.anadirClientes(Habitual, i);
		}
		else if (tipoCliente == 1) {
			cout << "Cliente " << i << ": ";
			//ClienteEsporadico Esporadico;
			//cin >> Esporadico;
			//reserva.anadirClientes(Esporadico, i);
		}
		else cout << "Tipo de cliente incorrecto"<<endl;
	}

	return is;
}
int Reserva::numTipoHabitacion() {
	return tipoHabitacion;
}