#include "builder.h"

void builder_test() {
	Direktor k0cc4;
	k0cc4.setGraditeljRacunara(new DesktopGraditelj());
	auto racunar = k0cc4.getRacunar();

	racunar->start();

	delete racunar;
}
