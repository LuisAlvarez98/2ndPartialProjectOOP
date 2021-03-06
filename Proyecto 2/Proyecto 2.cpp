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


//DONE
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
//DONE
void mostrarActores() 
{
	cout << "Id" << " " << " Nombre" << "\n";
	int i;
	for (i = 0; i < actoresSize; i++)
	{
		actores[i].muestra();
	}
}
//DONE
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
	ifArchivoPeliculas.close();
}
//DONE
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
//DONE
void mostrarPeliculas() 
{
	int index, i, j;
	cout << "Titulo" << "\t" << "Year" << "\t" << "Duracion" << "\t" << "Genero" << "\t" << "Actores/Actrices" << "\t" << "\n";
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
//DONE
void mostrarFunciones() 
{
	int i;
	cout << "Funciones disponibles: " << "\n";
	for (i = 0; i < numFunciones; i++) 
	{
		funciones[i].muestra();
	}
}

void addFunciones(int numFunciones)
{
	int i, j, numPeli, sala, hh, mm;
	string cveFuncion, titulo;
	
	int p;

	for (i = 0; i < numFunciones; i++)
	{	
		bool existeClave = true;
		bool existePelicula = true;
		bool existeSalaHora = true;

			while (existeClave) {
				int counter = 0;
				cout << "Ingresa la clave de la funcion" << "\n";
				cin >> cveFuncion;
				for (int z = 0; z < numFunciones; z++) {
					if (cveFuncion == funciones[z].getCveFuncion()) {
						counter++;
					}
				}
				if (counter > 0) {
					cout << "Ingresar una clave que no exista" << "\n";
					existeClave = true;
				}
				else if (counter == 0) {
					funciones[i].setCveFuncion(cveFuncion);
					existeClave = false;
				}
			}
				
			while (existePelicula) {
				int counter = 0;
				cout << "Ingresa el numero de la pelicula" << "\n";
				cin >> numPeli;
				for (int z = 0; z < peliculasSize; z++) {
					if (numPeli != peliculas[z].getNumPeli()) {
						counter++;
					}
				}
				if (counter == peliculasSize - 1) {
					existePelicula = false;
					funciones[i].setNumPeli(numPeli);
				}
				else if (counter == peliculasSize) {
					existePelicula = true;
					cout << "Numero de pelicula no existe" << "\n";
				}
			}
			
			while (existeSalaHora) {
				int counter = 0;
				bool flag = true;
				while (flag) {
					cout << "Hora de agregar la hora de la pelicula: " << "\n";
					cout << "Ingresa la hora en (hh)" << "\n";
					cin >> hh;
					cout << "Ingresa los minutos en (mm)" << "\n";
					cin >> mm;
					if (hh >= 0 && mm <= 23) {
						flag = false;
					}
					else if (hh <= -1 || mm >= 24) {
						flag = true;
						cout << "Ingresar una hora correcta" << "\n";
					}
				}
				cout << "Ingresa el numero de la sala" << "\n";
				cin >> sala;

				Hora hora(hh, mm);

				for (int o = 0; o < numFunciones; o++) {
					if ((hh == funciones[o].getHora().getHh() && mm == funciones[o].getHora().getMm()) && (sala == funciones[o].getSala())) {
						counter++;
					}
				}
				if (counter > 0) {
					existeSalaHora = true;
					cout << "No puedes agregar una hora igual con la misma sala" << "\n";
				}
				else if (counter == 0) {
					existeSalaHora = false;
					funciones[i].setHora(hora);
					funciones[i].setSala(sala);
				}
			}
		
				for (j = 0; j < peliculasSize; j++) {
					if (peliculas[j].getNumPeli() == numPeli) {
						funciones[i].setTitulo(peliculas[j].getTitulo());
					}
				}
	}
}

//DONE
void mostrarPorClaveFuncion()
{
	string claveUsuario;
	int i,j,k, index, p, counter = 0;
	bool funcionNoExiste = true;
	while (funcionNoExiste) {
		cout << "Ingresa clave de funcion porfavor" << "\n";
		cin >> claveUsuario;
		for (p = 0; p < numFunciones; p++) {
			if (claveUsuario == funciones[p].getCveFuncion()) {
				counter++;
			}
		}
		if (counter > 0) {
			for (i = 0; i < numFunciones; i++)
			{
				if (funciones[i].getCveFuncion() == claveUsuario)
				{
					cout <<"Sala: " << funciones[i].getSala() << ", " << "Titulo: " << funciones[i].getTitulo() << ", ";
					cout << "Hora: ";
					funciones[i].getHora().muestra();
					cout << ", ";
					for (j = 0; j < peliculasSize; j++)
					{
						if (peliculas[j].getTitulo() == funciones[i].getTitulo())
						{
							cout <<"Duracion: " << peliculas[j].getDuracion() <<" minutos" << ", " << "Genero: " << peliculas[j].getGenero() << ", ";
							cout << "Actores/Actrices: ";
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
			funcionNoExiste = false;
		}
		else if (counter == 0) {
			cout << "Clave invalida" << "\n";
			funcionNoExiste = true;
		}
	}
}
//DONE
void mostrarPeliculasActor() 
{
	int id, i, j, k, p;
	int counter = 0, nHay = 0;
	bool idExiste = true;
	while (idExiste) {
		cout << "Ingresar id del actor" << "\n";
		cin >> id;
		for (p = 0; p < actoresSize; p++) {
			if (id == actores[p].getId()) {
				counter++;
			}
		}
		if (counter > 0) {
			for (i = 0; i < actoresSize; i++)
			{
				if (id == actores[i].getId()) {
					for (j = 0; j < peliculasSize; j++)
					{
						for (k = 0; k < peliculas[j].getCantidadActores(); k++)
						{
							if (peliculas[j].getListaActores(k) == id)
							{
								cout <<"Titulo: " << peliculas[j].getTitulo() << ", " << "Year: " << peliculas[j].getYear() << "\n";
								nHay++;
							}
						}
					}
					cout << "\n";
					idExiste = false;
					if (nHay == 0) {
						cout << "No hay peliculas donde aparezca este actor/actriz:" << " ";
						obtenerNombresActores(id);
						cout << "\n";
					}
				}
			}
		}
		else if (counter == 0) {
			cout << "Id Invalido" << "\n";
			idExiste = true;
		}
	}
	
}
//DONE
void mostrarFuncionHora()
{
	int hh, mm, i, counter = 0;	
	bool invalid = true;
	while (invalid) {
		cout << "Ingresar hora:" << "\n";
		cout << "Ingresar hora (hh):" << "\n";
		cin >> hh;
		cout << "Ingresar minutos(mm):" << "\n";
		cin >> mm;
		if ((hh >= 0 && hh <= 23) && (mm >= 0 && mm <= 59)) {
			for (i = 0; i < numFunciones; i++)
			{
				if ((funciones[i].getHora().getHh() == hh) && (funciones[i].getHora().getMm() == mm))
				{
					cout <<"Pelicula: " << funciones[i].getTitulo() << ", " << "Sala: " << funciones[i].getSala() << "\n";
					counter++;
				}
			}
			invalid = false;
			if (counter == 0) {
				cout << "No se han encontrado peliculas con este horario" << "\n";
			}
		}
		else if ((hh <= -1) || (hh > 23) || (mm <= -1 || mm > 59)) {
			invalid = true;
			cout << "Hora invalida" << "\n";
		}
	}
}
//DONE
void menu() 
{
	bool updater = true;
	char option;
	while (updater) 
	{
		cout << "Proyecto Luis Felipe Alvarez - Menu:" << "\n";
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
//DONE
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

