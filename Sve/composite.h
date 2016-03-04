#pragma once

#include <iostream>
#include <string>
#include <list>
using namespace std;

/* Komponenta (interfejs) */
class Komponenta {
public:
	Komponenta(string ime, double plata) : m_Ime(ime), m_plata(plata) {}

	virtual void getPlata(int level) const = 0;

protected:
	string m_Ime;
	double m_plata;
};

/* List hijerarhije - obican radnik */
class Radnik : public Komponenta {
public:
	Radnik(string ime, double plata) : Komponenta(ime, plata) {}

	void getPlata(int level) const {
		for (int j = 0; j < level; ++j) cout << "\t";
		cout << "Radnik : " << m_Ime.c_str() << ", plata: $" << m_plata << "\n";
	}
};

/* Kompozit */
class Menadzer : public Komponenta {
public:
	Menadzer(string ime, double plata) : Komponenta(ime, plata) {}

	void add(Komponenta *cmp) {
		m_tim.push_back(cmp);
	}

	void getPlata(int nivo) const {
		for (int j = 0; j < nivo; ++j) cout << "\t";
		cout << "Menadzer : " << m_Ime.c_str() << ", plata: $" << m_plata << "\n";

		if (!m_tim.empty()) {
			for (int x = 0; x < nivo; ++x) cout << "\t";
			cout << "Tim saradnika " << m_Ime.c_str() << ":\n";
			++nivo;
			for (auto mate : m_tim) {
				mate->getPlata(nivo);
			}
		}
	}
private:
	list<Komponenta*> m_tim;
};

void composite_test();