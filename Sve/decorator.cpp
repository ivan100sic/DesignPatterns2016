#pragma once

#include "decorator.h"

void decorator_test() {
	Knjiga knjiga("Radoje Domanovic", "Vodja", 237);
	knjiga.info();

	/*Transforacija knjige u bubliotecki element koji moze da se izdaje */
	ZaIzdavanje knjigaZaIzd(&knjiga);
	knjigaZaIzd.pozajmi("Svetozar Stancic");
	knjigaZaIzd.info();

	/* Kreiranje biblioteckog elementa koji predstavlja video sadrzaj*/
	Video video("Slobodan Sijan", "Ko to tamo peva", 86, 24);
	video.info();

	/* Transformacija videa u bubliotecki element koji moze da se izdaje */
	ZaIzdavanje videoZaIzd(&video);
	videoZaIzd.pozajmi("Petar Petrovic");
	videoZaIzd.pozajmi("Nikola Nikolic");
	videoZaIzd.info();
	videoZaIzd.vrati("Nikola Nikolic");
	videoZaIzd.info();
}