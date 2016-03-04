#include "prototype.h"

// Pen

Pen* Pen::protoArray[10];

Pen* Pen::create(int idx) {
	Pen* proto;
	if (proto = protoArray[idx])
		return proto->clone();
	return nullptr;
}

Pen* Pen::addPrototype(int idx, Pen* p) {
	protoArray[idx] = p;
	return p;
}

void Pen::destroyPrototypes() {
	for (int i = 0; i < 10; ++i)
		delete protoArray[i];
}

// FountainPen

Pen* FountainPen::clone() const {
	return new FountainPen(*this);
}

// RollerBallPen

Pen* RollerBallPen::clone() const {
	return new RollerBallPen(*this);
}

void prototype_test() {
	Pen::addPrototype(0, new FountainPen("Golden 14K"));
	Pen::addPrototype(1, new FountainPen("Golden 21K"));
	Pen::addPrototype(2, new RollerBallPen("0.7"));
	Pen::addPrototype(3, new BallPointPen("0.5"));
	Pen* ptrPen = Pen::create(1);
	ptrPen->Write();
	delete ptrPen;
	ptrPen = Pen::create(2);
	ptrPen->Write();
	delete ptrPen;
	ptrPen = Pen::create(3);
	ptrPen->Write();
	delete ptrPen;
	Pen::destroyPrototypes();
}