// Proyecto 2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pelicula.h"
#include "Funcion.h"
#include "Actor.h"
#include <fstream>


Actor actores[20];
Funcion funciones[20];
Pelicula peliculas[20];
ifstream ifArchivoEntrada;
//Carga los actores
void cargarActores(){
	int id;
	string nombre;
	ifArchivoEntrada.open("Actores.txt");
	while (ifArchivoEntrada >> id && getline(ifArchivoEntrada, nombre)) {
		cout << id << " " << nombre << "\n";
	}
	ifArchivoEntrada.close();
}

void menu() {
	bool updater = true;
	char option;
	while (updater) {
		cout << "Menu:" << "\n";
		cout << "a.Consulta de todos los actores que estan en la lista" << "\n";
		cout << "b.Consulta de todas las peliculas que estan en la lista" << "\n";
		cout << "c.Consulta de todas las funciones disponibles" << "\n";
		cout << "d.Consulta de funciones por hora" << "\n";
		cout << "e.Consulta por clave de funcion" << "\n";
		cout << "f.Consulta la lista de peliculas en las que participa un actor" << "\n";
		cout << "g.Terminar" << "\n";
		cin >> option;
		switch (option) {
			case 'a':
				cout << "a" << "\n";
				break;
			case 'b':
				cout << "b" << "\n";
				break;
			case 'c':
				cout << "c" << "\n";
				break;
			case 'd':
				cout << "d" << "\n";
				break;
			case 'e':
				cout << "e" << "\n";
				break;
			case 'f':
				cout << "f" << "\n";
				break;
			case 'g':
				cout << "g" << "\n";
				updater = false;
				break;
		}
	}
	
}

int main()
{
	
	cargarActores();
    return 0;
}

