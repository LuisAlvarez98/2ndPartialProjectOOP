#pragma once
#include <string>
#include <iostream>
using namespace std;

class Pelicula {
	private:
		int numPeli;
		string titulo;
		int year;
		int duracion;
		string genero;
		int cantidadActores;
		int *listaActores;
	public:
		//Constructor default
		Pelicula() {
			this->listaActores = new int[10];
			this->numPeli = 0;
			this->year = 0;
			this->titulo = " ";
			this->duracion = 0;
			this->genero = " ";
			this->cantidadActores = 0;
		}
		//Metodos de acceso y modificadores
		void setNumPeli(int numPeli) {
			this->numPeli = numPeli;
		}
		int getNumPeli() {
			return this->numPeli;
		}
		void setTitulo(string titulo) {
			this->titulo = titulo;
		}
		string getTitulo() {
			return this->titulo;
		}
		void setYear(int year) {
			this->year = year;
		}
		int getYear() {
			return this->year;
		}
		void setGenero(string genero) {
			this->genero = genero;
		}
		string getGenero() {
			return this->genero;
		}
		void setDuracion(int duracion) {
			this->duracion = duracion;
		}
		int getDuracion() {
			return this->duracion;
		}
		int getCantidadActores() {
			return this->cantidadActores;
		}
		//End metodos de acceso y modificacion
		int getListaActores(int index) {
			return this->listaActores[index];
		}
		bool agregarActor(int id) 
		{
			int i;
			bool flag = true, duplicado = false;
			if (cantidadActores >= 10) 
			{
				flag = false;
			}else if (flag = true) 
			{
				for (i = 0; i < cantidadActores; i++)
				{
					if (id == listaActores[i]) 
					{
						duplicado = true;
						flag = false;
					}
				}
				if (!duplicado) 
				{
					listaActores[cantidadActores] = id;
					cantidadActores++;
					flag = true;
				}
			}
			return flag;
		}
		
};	