#include<iostream>
#include "Hotel.h"

int main() {
	int opcionSeleccionada = 0;
	string aux;
	Cliente clientAux;
	Hotel hotel;
	while (opcionSeleccionada != 10) {
		cout << "~~~~~~~~~~~~Menu Recepcionista hotel~~~~~~~~~~~~\n" << endl
			<< "1. Consultar precio de una habitacion\n2. Consultar descuento\n3. Modificar descuento para clientes habituales" << endl
			<< "4. Cambiar precio habitacion\n5. Mostrar precio de una reserva\n6. Reservar Habitacion\n7. Calcular ganancias de un mes" << endl
			<< "8. Lista de las habitaciones\n9. Guardar\n10. Salir" << endl << "Seleccione una opcion: ";
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
			cout << clientAux<<" tiene un descuento de: " << hotel.consultarDescuento(clientAux) << "%\n" << endl;
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
			break;
		default:
			cout << "Numero seleccionado erroneo." << endl;
			break;
		}
	}
}