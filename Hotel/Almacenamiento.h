#pragma once
#include<iostream>
#include<fstream>
using namespace std;

template <class T> class Almacenamiento;

template <class T> class Almacenamiento {
private:
	T tipo;
	string nombreArchivo;

public:
	Almacenamiento<T>();
	Almacenamiento<T>(string);
	void guardar(T clase[], int);
	void cargar(T clase[], int, int);
};

template<class T> Almacenamiento<T>::Almacenamiento<T>() {
	nombreArchivo = "documento.txt";
}
template<class T> Almacenamiento<T>::Almacenamiento<T>(string nombreArchivo) {
	this->nombreArchivo = nombreArchivo;
}

template<class T> void Almacenamiento<T>::guardar(T datosAnadir[], int numMax) {
	ofstream archivo(nombreArchivo);
	if (archivo.is_open()) {
		for (int i = 0; i < numMax; i++) {
			archivo << datosAnadir[i] << "\n";//probar con endl
		}
		archivo.close();
		cout << "Guardado correctamente." << endl;
	}
	else {
		cout << "No se ha podido abrir el archivo." << endl;//cambiar cerr
	}
}
template<class T> void Almacenamiento<T>::cargar(T datosCargar[], int numMax, int numAtributos) {
	ifstream archivoEntrada(nombreArchivo);
	if (archivoEntrada.is_open()) {
		for (int i = 0; i < numMax; i+=4) {
			archivoEntrada >> datosCargar[i];/*
			if (!(archivoEntrada >> datosCargar[i])) {
				cerr << "Error al leer desde archivo." << endl;
			}*/
		}
	}
	else {
		cout << "No se ha podido abrir el archivo." << endl;
	}
}