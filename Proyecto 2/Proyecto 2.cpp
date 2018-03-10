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

ifstream ifArchivoActores;
ifstream ifArchivoPeliculas;
int actoresSize;
int peliculasSize;

//Carga los actores
void cargarActores(){
	int id;
	string nombre;
	ifArchivoActores.open("Actores.txt");
	while (ifArchivoActores >> id && getline(ifArchivoActores, nombre)) {
		actores[actoresSize].setId(id);
		actores[actoresSize].setNombre(nombre);
		actoresSize++;
	}
	ifArchivoActores.close();
}
//Muestra Actores
void mostrarActores() {
	cout << "Id" << " " << " Nombre" << "\n";
	for (int i = 0; i < actoresSize; i++) {
		cout << actores[i].getId() << " " << actores[i].getNombre() << "\n";
	}
}
//Carga las peliculas
void cargarPeliculas() 
{
	int numPeli, year, duracion, cantidadActores, *listaActores, iX;
	listaActores = new int[10];
	string genero, titulo;
	
	ifArchivoPeliculas.open("Peliculas.txt");
	while (ifArchivoPeliculas >> numPeli >> year >> duracion >> genero >> cantidadActores) 
	{
		for (iX = 0; iX < cantidadActores; iX++) {
			ifArchivoPeliculas >> listaActores[iX];
			peliculas[peliculasSize].agregarActor(listaActores[iX]);
		}
		getline(ifArchivoPeliculas, titulo);
		peliculas[peliculasSize].setNumPeli(numPeli);
		peliculas[peliculasSize].setYear(year);
		peliculas[peliculasSize].setGenero(genero);	
		peliculas[peliculasSize].setTitulo(titulo);
		peliculas[peliculasSize].setDuracion(duracion);
		
		peliculasSize++;
	}
}
void obtenerNombresActores(int id) {
	for (int i = 0; i < actoresSize; i++) {
		if (actores[i].getId() == id) {
			cout << actores[i].getNombre() << " ";
		}
	}
}
//Muestra las peliculas
void mostrarPeliculas() {
	int index;
	for (int i = 0; i < peliculasSize; i++) {
		cout << peliculas[i].getTitulo() << " " << peliculas[i].getYear() << " " << peliculas[i].getDuracion() << " " << peliculas[i].getGenero() << " ";
		for (int j = 0; j < peliculas[i].getCantidadActores(); j++) {
			index = peliculas[i].getListaActores(j);
			obtenerNombresActores(index);
		}
		cout << "\n";
	}
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
				mostrarActores();
				break;
			case 'b':
				mostrarPeliculas();
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
	cargarPeliculas();
	menu();
    return 0;
}

