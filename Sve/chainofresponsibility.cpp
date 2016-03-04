#include "chainofresponsibility.h"

void chainofresponsibility_test() {
	RadnikL<NIZAK> rad("Petar Djuric");
	RadnikL<SREDNJI> sup("Vojislav Mitrovic");
	RadnikL<VISOK> sef("Miroslav Stevanovic");
	rad.PostaviSefa(&sup);
	sup.PostaviSefa(&sef);
	sef.PostaviSefa(0);

	Upit q1("Mozes li da zavrsis ovaj zadatak?", NIZAK);
	Upit q2("Da li tim moze da zavrsi zadatak na vreme?", SREDNJI);
	Upit q3("Da li odeljenje proizvodnje moze da zavrsi zadatak?", VISOK);

	rad.ObradiUpit(q1);
	rad.ObradiUpit(q2);
	rad.ObradiUpit(q3);
}