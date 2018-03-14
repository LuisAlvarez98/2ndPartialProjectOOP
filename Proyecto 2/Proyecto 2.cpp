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
int numFunciones;


//Carga los actores
void cargarActores()
{
	int id;
	string nombre;
	ifArchivoActores.open("Actores.txt");
	while (ifArchivoActores >> id && getline(ifArchivoActores, nombre))
	{
		actores[actoresSize].setId(id);
		actores[actoresSize].setNombre(nombre);
		actoresSize++;
	}
	ifArchivoActores.close();
}
//Muestra Actores PASARLO a la clase
void mostrarActores() 
{
	int i;
	cout << "Id" << " " << " Nombre" << "\n";
	for (i = 0; i < actoresSize; i++) 
	{
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
		for (iX = 0; iX < cantidadActores; iX++) 
		{
			ifArchivoPeliculas >> listaActores[iX];
			peliculas[peliculasSize].agregarActor(listaActores[iX]);
		}
		getline(ifArchivoPeliculas, titulo);
		titulo.erase(0, 1);
		peliculas[peliculasSize].setNumPeli(numPeli);
		peliculas[peliculasSize].setYear(year);
		peliculas[peliculasSize].setGenero(genero);	
		peliculas[peliculasSize].setTitulo(titulo);
		peliculas[peliculasSize].setDuracion(duracion);
		
		peliculasSize++;
	}
}
void obtenerNombresActores(int id) 
{
	int i;
	for (i = 0; i < actoresSize; i++) 
	{
		if (actores[i].getId() == id)
		{
			cout << actores[i].getNombre() << " ";
		}
	}
}
//Muestra las peliculas
void mostrarPeliculas() 
{
	int index, i, j;
	for (i = 0; i < peliculasSize; i++) 
	{
		cout << peliculas[i].getTitulo() << " " << peliculas[i].getYear() << " " << peliculas[i].getDuracion() << " " << peliculas[i].getGenero() << " ";
		for (j = 0; j < peliculas[i].getCantidadActores(); j++) 
		{
			index = peliculas[i].getListaActores(j);
			obtenerNombresActores(index);
		}
		cout << "\n";
	}
}
//Muestra funciones
void mostrarFunciones() 
{
	int i;
	for (i = 0; i < numFunciones; i++) 
	{
		funciones[i].muestra();
	}
}
//Agrega funciones
void addFunciones(int numFunciones)
{
	int i , j, numPeli, sala, hh, mm;
	string cveFuncion, titulo;

	for (i = 0; i < numFunciones; i++)
	{
		cout << "Ingresa la clave de la funcion" << "\n";
		cin >> cveFuncion;
		cout << "Ingresa el numero de la pelicula" << "\n";
		cin >> numPeli;
		cout << "Hora de agregar la hora de la pelicula: " << "\n";
		cout << "Ingresa la hora en (hh)" << "\n";
		cin >> hh;
		cout << "Ingresa los minutos en (mm)" << "\n";
		cin >> mm;
		Hora hora(hh, mm);
		cout << "Ingresa el numero de la sala" << "\n";
		cin >> sala;

		funciones[i].setCveFuncion(cveFuncion);
		funciones[i].setHora(hora);
		funciones[i].setSala(sala);
		funciones[i].setNumPeli(numPeli);
		for (j = 0; j < peliculasSize; j++) {
			if (peliculas[j].getNumPeli() == numPeli) {
				funciones[i].setTitulo(peliculas[j].getTitulo());
			}
		}
	}
}
//Needs validation
void mostrarPorClaveFuncion()
{
	string claveUsuario;
	int i,j,k, index;
	cout << "Ingresa clave de funcion porfavor" << "\n";
	cin >> claveUsuario;
	for (i = 0; i < numFunciones; i++) 
	{
		if (funciones[i].getCveFuncion() == claveUsuario) 
		{
			cout << funciones[i].getSala() << " " << funciones[i].getTitulo() << " ";
			funciones[i].getHora().muestra();
			for (j = 0; j < peliculasSize; j++) 
			{
				if (peliculas[j].getTitulo() == funciones[i].getTitulo())
				{
					cout << peliculas[j].getDuracion() << " " << peliculas[j].getGenero() << " ";
					for (k = 0; k < peliculas[j].getCantidadActores(); k++) 
					{
						index = peliculas[j].getListaActores(k);
						obtenerNombresActores(index);
					}
				}
			
			}
		}
		cout << "\n";
	}
}
//Needs validation
void mostrarPeliculasActor() 
{
	int id, i, j, k;
	cout << "Ingresar id del actor" << "\n";
	cin >> id;
	bool noExiste, flag;

	for (i = 0; i < actoresSize; i++) 
	{
		if (id == actores[i].getId()) {
			for (j = 0; j < peliculasSize; j++)
			{
				for (k = 0; k < peliculas[j].getCantidadActores(); k++) 
				{
					if (peliculas[j].getListaActores(k) == id) 
					{
						cout << peliculas[j].getTitulo() << " " << peliculas[j].getYear() << "\n";
					}
				}
			}
			cout << "\n";
		}
	}
}
//Mostrar funcion por hora
void mostrarFuncionHora()
{
	int hh, mm, i;		
	cout << "Ingresar hora:" << "\n";
	cout << "Ingresar hora (hh):" << "\n";
	cin >> hh;
	cout << "Ingresar minutos(mm):" << "\n";
	cin >> mm;
	for (i = 0; i < numFunciones; i++) 
	{
		if ((funciones[i].getHora().getHh() == hh) && (funciones[i].getHora().getMm() == mm)) 
		{
			cout << funciones[i].getTitulo() << " " << funciones[i].getSala() << "\n";
		}
	}
}
//Menu
void menu() 
{
	bool updater = true;
	char option;
	while (updater) 
	{
		cout << "Menu:" << "\n";
		cout << "a.Consulta de todos los actores que estan en la lista" << "\n";
		cout << "b.Consulta de todas las peliculas que estan en la lista" << "\n";
		cout << "c.Consulta de todas las funciones disponibles" << "\n";
		cout << "d.Consulta de funciones por hora" << "\n";
		cout << "e.Consulta por clave de funcion" << "\n";
		cout << "f.Consulta la lista de peliculas en las que participa un actor" << "\n";
		cout << "g.Terminar" << "\n";
		cin >> option;
		switch (option)
		{
			case 'a':
				mostrarActores();
				break;
			case 'b':
				mostrarPeliculas();
				break;
			case 'c':
				mostrarFunciones();
				break;
			case 'd':
				mostrarFuncionHora();
				break;
			case 'e':
				mostrarPorClaveFuncion();
				break;
			case 'f':
				mostrarPeliculasActor();
				break;
			case 'g':
				cout << "g" << "\n";
				updater = false;
				break;
		}
	}
	
}
//Main
int main()
{
	//Carga Actores y Peliculas del archivo de texto
	cargarActores();
	cargarPeliculas();
	//Agrega las funciones
	cout << "Cuantas funciones quieres agregar para el dia de hoy?" << "\n";
	cin >> numFunciones;
	addFunciones(numFunciones);

	//Corre el menu
	menu();


    return 0;
}

