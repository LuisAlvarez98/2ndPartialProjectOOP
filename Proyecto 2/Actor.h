#pragma once
	#include <string>
	using namespace std;
class Actor {
	private:
		int id;
		string nombre;
	public:
		//Constructor default
		Actor() {
			this->id = 0;
			this->nombre = " ";
		}
		//Constructor
		Actor(int id, string nombre) {
			this->id = id;
			this->nombre = nombre;
		}
		//Metodos de acceso y modificacion
		inline void setId(int id) {
			this->id = id;
		}
		inline int getId() {
			return this->id;
		}
		inline void setNombre(string nombre) {
			this->nombre = nombre;
		}
		inline string getNombre() {
			return this->nombre;
		}
		//Muestra
		void muestra() {
			cout << this->id << " " << this->nombre << "\n";
		}
};