#pragma once

#include <string>
#include <iostream>
using namespace std;

class Pen {
	string type;
	static Pen* protoArray[];
public:
	Pen(const string &ty) :type(ty) {}
	Pen(const Pen &other) :type(other.type) {}
	virtual ~Pen() {}
	virtual Pen* clone() const = 0;
	virtual void Write() const { cout << "\nVrh pera " << type << endl; }
	static Pen* create(int idx);
	static Pen* addPrototype(int idx, Pen* p);
	static void destroyPrototypes();
};

class FountainPen : public Pen {
public:
	FountainPen(const string &ty) :Pen(ty) {}
	FountainPen(const FountainPen& other) : Pen(other) {}
	virtual Pen* clone() const;
	virtual void Write() const {
		cout << "\nNaliv pero " << endl;
		Pen::Write();
	}
};

class RollerBallPen : public Pen {
public:
	RollerBallPen(const string &ty) :Pen(ty) {}
	RollerBallPen(const RollerBallPen& other) : Pen(other) {}
	virtual Pen* clone() const;
	virtual void Write() const {
		cout << "\nRoller " << endl;
		Pen::Write();
	}
};

template<class Derived>
class CloneablePen : public Pen {
public:
	CloneablePen(const string& ty) : Pen(ty) {}

	CloneablePen(const CloneablePen& other) : Pen(other) {}

	virtual Pen* clone() const {
		return new Derived(*(Derived*)this);
	}
};

class BallPointPen : public CloneablePen<BallPointPen> {
public:
	BallPointPen(const string& ty) : CloneablePen<BallPointPen>(ty) {}

	BallPointPen(const BallPointPen& other) :
		CloneablePen<BallPointPen>(other) {}

	virtual void Write() const {
		cout << "\nOlovka" << endl;
		Pen::Write();
	}

	/* Ova klasa implementira metodu clone
	tako sto je nasledjuje iz instance sablona
	CloneablePen<BallPointPen> */
};

void prototype_test();