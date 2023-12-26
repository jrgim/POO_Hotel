#include "Reserva.h"
Reserva::Reserva(){
    Clientes = new Cliente[numClientes];
    numNoches=0;
    fechaEntrada = "10/12/2023";
    numHabitacion= 0;
}

Reserva::Reserva(int numNoches, string fechaEntrada, int numHabitacion){
    this->numNoches = numNoches;
    this->fechaEntrada = fechaEntrada;
    this->numHabitacion=numHabitacion;
}
