#pragma once
#include <string>
#include "Hora.h"
using namespace std;

class Funcion {
	private:
		string cveFuncion;
		int numPeli;
		Hora hora;
	public:
		//Constructor FALTA DEFAULT
		Funcion(string cveFuncion, int numPeli, Hora hora) {
			this->cveFuncion = cveFuncion;
			this->numPeli = numPeli;
			this->hora = hora;
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
		string getCveFuncion() {
			return this->cveFuncion;
		}
		int getNumPeli() {
			return this->numPeli;
		}
		Hora getHora() {
			return this->hora;
		}
};