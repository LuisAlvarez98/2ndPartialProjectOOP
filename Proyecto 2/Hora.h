#pragma once
class Hora {
	private:
		int hh;
		int mm;
	public:
		Hora() {
			this->hh = 0;
			this->mm = 0;
		}
		//Constructor FALTA DEFAULT
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
};