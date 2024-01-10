#include<iostream>
#include<Windows.h>
#include "Hotel.h"
#define color SetConsoleTextAttribute

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int opcionSeleccionada = 0, selecionNum=-1;
	string aux;
	Cliente clientAux;
	Hotel hotel;

	while (opcionSeleccionada != 11) {
		color(hConsole, 1);
		cout << "~~~~~~~~~~~~Menu Recepcionista hotel~~~~~~~~~~~~\n" << endl;
		color(hConsole, 2);
		cout << "1. Consultar precio de una habitacion\n";
		color(hConsole, 3);
		cout << "2. Consultar descuento\n";
		color(hConsole, 5);
		cout << "3. Modificar descuento para clientes habituales" << endl;
		color(hConsole, 6);
		cout << "4. Cambiar precio habitacion\n";
		color(hConsole, 7);
		cout << "5. Mostrar precio de una reserva\n";
		color(hConsole, 9);
		cout << "6. Reservar Habitacion\n";
		color(hConsole, 10);
		cout << "7. Calcular ganancias de un mes" << endl;
		color(hConsole, 1);
		cout << "8. Lista de las habitaciones\n";
		color(hConsole, 2);
		cout << "9. Guardar\n";
		color(hConsole, 3);
		cout << "10. Cargar datos\n";
		color(hConsole, 4);
		cout << "11. Salir" << endl;
		color(hConsole, 3);
		cout << "Seleccione una opcion: ";
		cin >> opcionSeleccionada;
		switch (opcionSeleccionada)
		{
		case 1://Consultar precio Habitacion
			hotel.consultarPrecioHabitacion();
			break;
		case 2://Consultar descuento
			cout << "Nombre del cliente a buscar: ";//hacer cambio todo a mayusculas
			cin >> aux;
			clientAux=hotel.buscarCliente(aux);
			clientAux.leerCliente();
			cout << " tiene un descuento de: " << hotel.consultarDescuento(clientAux) << "%\n" << endl;
			break;
		case 3://Modificar descuento

			break;
		case 4://Cambiar precio habitacion

			break;
		case 5://Mostrar precio de una reserva

			break;
		case 6://Reservar una habitacion
			hotel.reservarHabitacion();
			break;
		case 7://Calcular ganancias de un mes

			break;
		case 8://Lista de las habitaciones
			hotel.listaHabitaciones();
			break;
		case 9://Guardar
			hotel.guardar();
			break;
		case 10:
			hotel.cargar();
			break;
		case 11:
			cout << "\nQueres guardar los cambios antes de cerrar:0. NO / 1. SI: ";
			cin >> selecionNum;
			if (selecionNum == 1) {
				hotel.guardar();
				cout << "\nDATOS GUARDADOS";
			}
			else cout << "\nDATOS BORRADOS\n";
			break;
		default:
			cout << "Numero seleccionado erroneo." << endl;
			break;
		}
	}
}