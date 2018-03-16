#pragma once
#include "Hora.h"
using namespace std;

class Funcion {
	private:
		string cveFuncion;
		int numPeli;
		Hora hora;
		int sala;
		string titulo;
	public:
		//Constructor default
		Funcion() {
			this->cveFuncion = ' ';
			this->numPeli = 0;
			this->hora = Hora();
			this->sala = 0;
		}
		//Constructor FALTA DEFAULT
		Funcion(string cveFuncion, int numPeli, Hora hora, int sala) {
			this->cveFuncion = cveFuncion;
			this->numPeli = numPeli;
			this->hora = hora;
			this->sala = sala;
		}
		//Metodos de acceso y modificacion
		void setCveFuncion(string cveFuncion) {
			this->cveFuncion = cveFuncion;
		}
		void setNumPeli(int numPeli) {
			this->numPeli = numPeli;
		}
		void setHora(Hora hora) {
			this->hora = hora;
		}
		void setSala(int sala) {
			this->sala = sala;
		}
		string getCveFuncion() {
			return this->cveFuncion;
		}
		int getNumPeli() {
			return this->numPeli;
		}
		Hora getHora() {
			return this->hora;
		}
		int getSala() {
			return this->sala;
		}
		//Muestra
		void muestra() {
			cout <<"Clave: " << cveFuncion << ", " << "Titulo: " << titulo <<  ", " << "Sala: " << sala << ", ";
			cout << "Hora: ";
			hora.muestra();
			cout << "\n";
		}
		void setTitulo(string titulo) {
			this->titulo = titulo;
		}
		string getTitulo() {
			return this->titulo;
		}
};