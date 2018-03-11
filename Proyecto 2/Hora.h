#pragma once
#include <iostream>
#include <string>
using namespace std;

class Hora {
	private:
		int hh;
		int mm;
	public:
		//Constructor Default
		Hora() {
			this->hh = 0;
			this->mm = 0;
		}
		//Constructor
		Hora(int hh, int mm) {
			this->hh = hh;
			this->mm = mm;
		}
		//Metodos de acceso y modificacion
		void setHh(int hh) {
			this->hh = hh;
		}
		void setMm(int mm) {
			this->mm = mm;
		}
		int getHh() {
			return this->hh;
		}
		int getMm() {
			return this->mm;
		}
		//Muestra
		void muestra() {
			cout << this->hh << ":" << this->mm << " ";
		}
};