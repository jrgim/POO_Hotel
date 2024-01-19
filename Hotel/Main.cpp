#include<iostream>
#include<Windows.h>
#include "Hotel.h"
#include "Excepcion_digito.h"
#define color SetConsoleTextAttribute

int main() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int opcionSeleccionada = 0, opcDos=-1, selecionNum=-1;
	string aux;
	char entrada;
	Cliente clientAux;
	Hotel hotel;

	while (opcionSeleccionada != 9) {
		color(hConsole, 1);
		cout << "~~~~~~~~~~~~Menu Recepcionista hotel~~~~~~~~~~~~\n" << endl;
		color(hConsole, 2);
		cout << "1. Lista de las habitaciones\n";
		color(hConsole, 3);
		cout << "2. Consultar o modificar el precio de una habitacion\n";
		color(hConsole, 5);
		cout << "3. Consultar o modificar el descuento" << endl;
		color(hConsole, 6);
		cout << "4. Consultar precio total de un cliente\n";
		color(hConsole, 7);
		cout << "5. Nueva reserva\n";
		color(hConsole, 9);
		cout << "6. Eliminar reserva\n";
		color(hConsole, 10);
		cout << "7. Calcular ganancias en un mes" << endl;
		color(hConsole, 1);
		cout << "8. Guardar o cargar datos\n";
		color(hConsole, 2);
		cout << "9. Salir\n";
		color(hConsole, 3);
		cout << "Seleccione una opcion: ";
		cin >> entrada;

		try {
			opcionSeleccionada = entrada - '0';
		}
		catch (invalid_argument& ia) {
			cout << ia.what() << endl;
		}

		switch (opcionSeleccionada)
		{
		case 1: // Lista de las habitaciones
			hotel.listaHabitaciones();
			break;
		case 2: //Consultar el precio de una habitacion y Modificar el precio de una habitacion
			cout << "Seleccione una opcion: 0. Consultar precio de las habitaciones, 1. Cambiar el precio de las habitaciones: ";
			cin >> opcDos;
			if (opcDos == 0) {
				hotel.consultarPrecioHabitacion();
			}
			else if (opcDos == 1) {
				hotel.cambiarPrecioHabitacion();
			}
			opcDos = -1;
			break;
		case 3: //Consultar descuento
			cout << "Seleccione una opcion: 0. Consultar descuento, 1. modificar descuento: ";
			cin >> opcDos;
			if (opcDos == 0) {
				clientAux = hotel.buscarCliente();
				clientAux.leerCliente();
				cout << " tiene un descuento de: " << hotel.consultarDescuento(clientAux) << "%\n" << endl;
			}
			else if (opcDos == 1) {//Modificar descuento
				hotel.modificarDescuento();
			}
			break;
		case 4: //Consultar precio total de un cliente
			clientAux = hotel.buscarCliente();
			hotel.precioTotal(clientAux);
			break;
		case 5: //Nueva reserva
			hotel.reservarHabitacion();

			break;
		case 6: //Eliminar reserva
			hotel.eliminarReserva();					//Queda probarla.
			
			break;
		case 7: //Calcular ganancias en un mes

			break;
		case 8: //Guardar o cargar
			cout << "Seleccione una opcion: 0. Guardar datos, 1. Cargar datos";
			cin >> opcDos;
			if (opcDos == 0) {
				hotel.guardar();
			}
			else if (opcDos == 1) {
				hotel.cargar();
			}
			
			break;
		case 9: //Salir
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