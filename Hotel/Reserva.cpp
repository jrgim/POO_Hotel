#include "Reserva.h"
Reserva::Reserva(){
    numNoches=0;
	ClientesReserva = new Cliente[3];
    fechaEntrada = "10/12/2023";
    numHabitacion= 0;
	numClientesHabitacion = 0;
	tipoHabitacion = 3;
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


void Reserva::nuevaReserva() {
	int tipoCliente;
	Cliente cliente;
	cout << "Introduce el numero de noches: ";
	cin >> numNoches;
	cout << "\nIntroduce la fecha de entrada: ";
	cin >> fechaEntrada;
	cout << "\n Introduce el numero de personas a hospedar: ";
	cin >> numClientesHabitacion;
	while (numClientesHabitacion >= 3) {
		cout << "El numero maximo de personas por habitacion es de 2 personas." << endl;
		cout << "Introduce el numero de personas a hospedar : ";
		cin >> numClientesHabitacion;
	}

	cout << "Introduce el tipo de habitacion: 0: H.Simple, 1: H.Doble, 2: H.Matrimonio" << endl;
	cin >> tipoHabitacion;

	if (numClientesHabitacion == 1) {//Opcion solo 1 Huesped
		while (tipoHabitacion > 2) {
			cout << "Numero introducido erroneo. Introduce el tipo de habitacion: 0: H.Simple, 1: H.Doble, 2: H.Matrimonio" << endl;
			cin >> tipoHabitacion;
		}
	}
	if (numClientesHabitacion == 2) {
		if (tipoHabitacion == 0) {
			cout << "Habitacion pequena para 2 personas. Introduce el tipo de habitacion mas grande: 1: H.Doble, 2: H.Matrimonio: ";
			cin >> tipoHabitacion;
		}
		while (tipoHabitacion > 2) {
			cout << "Numero introducido erroneo. Introduce el tipo de habitacion: 0: H.Simple, 1: H.Doble, 2: H.Matrimonio: ";
			cin >> tipoHabitacion;
		}
	}

	//cambiar esto. solo quiero poner los tipos de habitaciones por numeros
	//quiero guardar los clientes en el hotel? o en la clase reserva?
	for (int i = 0; i < numClientesHabitacion; i++) {
		cout << "Cliente " << i << " seleccione tipo de cliente : 0. Habitual, 1. Esporadico : ";
		cin >> tipoCliente;
		if (tipoCliente == 0) {
			cout << "Cliente " << i << ": ";
			//cin >> cliente;
			ClienteHabitual Habitual;
			Habitual.nuevoCliente();
			anadirClientes(Habitual, i);
		}
		else if (tipoCliente == 1) {
			cout << "Cliente " << i << ": ";
			ClienteEsporadico Esporadico;
			Esporadico.nuevoCliente();
			anadirClientes(Esporadico, i);
		}
		else cout << "Tipo de cliente incorrecto" << endl;
	}
}
//Tenia puesto en la sobrecarga de >> lo que hace la funcion nuevaReserva, pero he preferido cambiarlo para poder cargar los datos desde los archivos.
istream& operator>>(istream& is, Reserva& reserva) {//TODO: Como guardar los clientes o seleccionarlos
	is >> reserva.numClientesHabitacion >> reserva.tipoHabitacion >> reserva.numNoches >> reserva.fechaEntrada >> reserva.numHabitacion;
	return is;
}
ostream& operator<<(ostream& os, const Reserva& reserva) {
	os << reserva.numClientesHabitacion << "\n" << reserva.tipoHabitacion << "\n" << reserva.numNoches << "\n" << reserva.fechaEntrada << "\n" << reserva.numHabitacion;
	return os;
}
int Reserva::numTipoHabitacion() {
	return tipoHabitacion;
}
void Reserva::anadirNumHabitacion(int numHabitacion) {
	this->numHabitacion = numHabitacion;
}
int Reserva::numHuespedes() {
	return numClientesHabitacion;
}
Cliente Reserva::Clientes(int indice) {
	return ClientesReserva[indice];
}

bool Reserva::buscarClientes(Cliente& cliente) {
	for (int i = 0; i < 2; i++) {
		if (cliente.obtenerNombre() == ClientesReserva[i].obtenerNombre()) {
			return true;
		}
	}
	return false;
}
int Reserva::obtenerNumHabitacion() {
	return numHabitacion;
}
int Reserva::obtenerNumNoches() {
	return numNoches;
}