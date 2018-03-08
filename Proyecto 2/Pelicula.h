#pragma once
#include <string>
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
		//Falta si se duplica
		bool agregarActor(int id) {
			bool flag;
			if (cantidadActores > 10) {
				flag = false;
			}else{
				listaActores[cantidadActores] = id;
				cantidadActores++;
				flag = true;
			}
			return flag;
		}
};	