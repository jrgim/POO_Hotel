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

	while (opcionSeleccionada != 12) {
		color(hConsole, 1);
		cout << "~~~~~~~~~~~~Menu Recepcionista hotel~~~~~~~~~~~~\n" << endl;
		color(hConsole, 2);
		cout << "1. Lista de las habitaciones\n";
		color(hConsole, 3);
		cout << "2. Consultar el precio de una habitacion\n";
		color(hConsole, 5);
		cout << "3. Modificar el precio de una habitacion" << endl;
		color(hConsole, 6);
		cout << "4. Consultar descuento\n";
		color(hConsole, 7);
		cout << "5. Modificar descuento\n";
		color(hConsole, 9);
		cout << "6. Consultar precio total de un cliente\n";
		color(hConsole, 10);
		cout << "7. Nueva reserva" << endl;
		color(hConsole, 1);
		cout << "8. Eliminar reserva\n";
		color(hConsole, 2);
		cout << "9. Calcular ganancias en un mes\n";
		color(hConsole, 6);
		cout << "10. Guardar\n";
		color(hConsole, 3);
		cout << "11. Cargar datos\n";
		color(hConsole, 4);
		cout << "12. Salir" << endl;
		color(hConsole, 3);
		cout << "Seleccione una opcion: ";
		cin >> opcionSeleccionada;


		switch (opcionSeleccionada)
		{
		case 1: // Lista de las habitaciones
			hotel.listaHabitaciones();
			break;
		case 2: //Consultar el precio de una habitacion
			hotel.consultarPrecioHabitacion();
			break;
		case 3: //Modificar el precio de una habitacion
			hotel.cambiarPrecioHabitacion();
			break;
		case 4: //Consultar descuento
			clientAux = hotel.buscarCliente();
			clientAux.leerCliente();
			cout << " tiene un descuento de: " << hotel.consultarDescuento(clientAux) << "%\n" << endl;
			break;
		case 5: //Modificar descuento

			break;
		case 6: //Consultar precio total de un cliente
			clientAux = hotel.buscarCliente();
			hotel.precioTotal(clientAux);				//Queda quitar el descuento!!!!
			break;
		case 7: //Nueva reserva
			hotel.reservarHabitacion();
			break;
		case 8: //Eliminar reserva
			hotel.eliminarReserva();					//Queda probarla. igual quitar el bool
			break;
		case 9: //Calcular ganancias en un mes

			break;
		case 10: //Guardar
			hotel.guardar();
			break;
		case 11: // Cargar datos
			hotel.cargar();
			break;
		case 12: //Salir
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