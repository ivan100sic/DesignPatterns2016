#pragma once

#include <string>
#include <iostream>
#include <list>
using namespace std;

class BiblElem {
public:
	BiblElem(size_t b) : kopija(b) {}

	void setBrKopija(size_t v) {
		kopija = v;
	}

	size_t getBrKopija() {
		return kopija;
	}

	virtual void info() = 0;

	virtual ~BiblElem() {}

private:
	size_t kopija;
};

class Knjiga : public BiblElem {
public:
	Knjiga(string autor, string naslov, size_t brKopija) :
		BiblElem(brKopija), autor(autor), naslov(naslov) {}

	void info() {
		cout << "\nKnjiga ------ \n";
		cout << " Autor : " << autor << "\n";
		cout << " Naslov : " << naslov << "\n";
		cout << " Broj kopija : " << getBrKopija() << endl;
	}

private:
	string autor;
	string naslov;
};

class Video : public BiblElem {
public:
	Video(string reziser, string naslov, int trajanje, size_t brKopija) :
		BiblElem(brKopija), reziser(reziser), naslov(naslov), trajanje(trajanje) {}

	void info() {
		cout << "\nVideo ------ \n";
		cout << " Reziser : " << reziser << "\n";
		cout << " Naslov : " << naslov << "\n";
		cout << " Trajanje : " << trajanje << "\n";
		cout << " Broj kopija : " << getBrKopija() << endl;
	}

private:
	string reziser;
	string naslov;
	int trajanje;
};

class Dekorater : public BiblElem {
public:
	Dekorater(BiblElem* ptr) : ptr(ptr), BiblElem(0) {}

	void info() {
		ptr->info();
	}

	size_t getBrKopija() const {
		return ptr->getBrKopija();
	}

	void setBrKopija(size_t b) {
		ptr->setBrKopija(b);
	}

protected:
	BiblElem* ptr;
};

class ZaIzdavanje : public Dekorater {
public:
	ZaIzdavanje(BiblElem* ptr) : Dekorater(ptr) {}

	void pozajmi(string ime) {
		size_t b = ptr->getBrKopija();
		if (b == 0) {
			cout << "Nemoguce pozajmiti ovu jedinicu!\n";
		} else {
			zajmici.push_back(ime);
			ptr->setBrKopija(b - 1);
		}
	}

	void vrati(string ime) {
		auto it = find(zajmici.begin(), zajmici.end(), ime);
		if (it == zajmici.end()) {
			cout << "Vi niste ni pozajmili ovu jedinicu!\n";
		} else {
			zajmici.erase(it);
			ptr->setBrKopija(ptr->getBrKopija() + 1);
		}
	}

	void info() {
		Dekorater::info();
		cout << "Broj pozajmljenih kopija : " << zajmici.size() << "\n";
		for (auto it : zajmici) {
			cout << "Korisnik : " << it << "\n";
		}
	}

protected:
	list<string> zajmici;
};

void decorator_test();