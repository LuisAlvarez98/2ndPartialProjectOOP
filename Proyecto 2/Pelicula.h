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
		int listaActores[10];
	public:
		Pelicula() {

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
		int getListaActores(int index) {
			return 0;
		}
};