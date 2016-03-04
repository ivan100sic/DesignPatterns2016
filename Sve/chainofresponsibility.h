#pragma once

#include <iostream>
using namespace std;

enum ENivoOdgovornosti { NIZAK = 1, SREDNJI, VISOK };

class Upit {
private:
	ENivoOdgovornosti m_nivo;
	string m_upit;
public:
	Upit(string upit, ENivoOdgovornosti nivo) : m_upit(upit), m_nivo(nivo) {}
	ENivoOdgovornosti NivoUpita() const { return m_nivo; }
	string StaJeUpit() const { return m_upit; }
};

class IOsoba {
private:
	string m_ime;
	IOsoba* m_sef;
public:
	IOsoba(string ime) :m_ime(ime) {};

	virtual void ObradiUpit(Upit upit) = 0;
	virtual string Ime() const { return m_ime; }
	virtual IOsoba* PtrToSef() const { return m_sef; }
	virtual void PostaviSefa(IOsoba* sef) { m_sef = sef; }

	/* Objekat nije odogovoran za unistavanje sledeceg clana u lancu odgovornosti */
	virtual ~IOsoba() {}
};

template<enum ENivoOdgovornosti nivo>
class RadnikL : public IOsoba {
public:
	RadnikL(string ime) : IOsoba(ime) {}
	virtual void ObradiUpit(Upit upit) {
		if (upit.NivoUpita() <= nivo) {
			/* Trenutni objekat u lancu JESTE sposoban da da odgovor */
			cout << "Odgovor na pitanje: " << upit.StaJeUpit().c_str()
				<< " je dao " << Ime().c_str() << endl;
			return;
		}
		/* Trenutni objekat u lancu NIJE sposoban da da odgovor */
		cout << "Osoba " << Ime().c_str()
			<< " ne moze da obradi trenutni upit. Upit se salje na dalju obradu: "
			<< (PtrToSef()->Ime()).c_str() << endl;
		/* Zahtev se salje na dalju obradu sledecem objektu u lancu odgovornosti */
		PtrToSef()->ObradiUpit(upit);
	}
};

void chainofresponsibility_test();