#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* Racunar, kaci mu se deo po deo */
class Racunar {
public:
	void setKomponenta(const string& deo) {
		komponente.push_back(deo);
	}
	void start() {
		for (auto deo : komponente) {
			cout << "Pokrecem " << deo << endl;
		}
		cout << "Racunar upaljen!" << endl;
	}
protected:
	vector<string> komponente;
};

/* Interfejs graditelja racunara */
class GraditeljRacunara {
public:
	virtual void zapocniGradnju() = 0;
	virtual void napraviProcesor() = 0;
	virtual void napraviMaticnu() = 0;
	virtual void napraviMonitor() = 0;
	virtual Racunar* vratiRezultat() = 0;
};

/* Primer kako treba da izgleda direktor gradnje */

class Direktor {
public:
	Direktor() : ptr(0) {}

	~Direktor() {
		delete ptr;
	}

	void setGraditeljRacunara(GraditeljRacunara* ptr) {
		delete this->ptr;
		this->ptr = ptr;
	}

	Racunar* getRacunar() {
		ptr->zapocniGradnju();
		ptr->napraviMaticnu();
		ptr->napraviMonitor();
		ptr->napraviProcesor();
		return ptr->vratiRezultat();
	}

private:
	GraditeljRacunara* ptr;
};

/* Jedan konkretni graditelj koji implementira interfejs */
class DesktopGraditelj : public GraditeljRacunara {
public:
	DesktopGraditelj() : ptr(0) {}

	virtual void zapocniGradnju() {
		delete ptr;
		ptr = new Racunar();
	}

	virtual void napraviProcesor() {
		ptr->setKomponenta("AMD FX-8320 8-core CPU");
	}

	virtual void napraviMaticnu() {
		ptr->setKomponenta("Gigabyte 990");
	}
	
	virtual void napraviMonitor() {
		ptr->setKomponenta("LG 22\" (primary)");
		ptr->setKomponenta("Acer 22\" (secondary)");
	}

	virtual Racunar* vratiRezultat() {
		return ptr;
		ptr = 0;
	}
protected:
	Racunar* ptr;
};

/* Mrzi me da pravim drugog graditelja, you get the idea */

void builder_test();