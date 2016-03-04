#pragma once

#include <string>
#include <iostream>
using namespace std;

/* Jedan veoma cheesy primer uzet direktno sa wikipedije */

struct SubsystemA {
	string OperationA1() {
		return "Subsystem A, Method A1\n";
	}

	string OperationA2() {
		return "Subsystem A, Method A2\n";
	}
};

struct SubsystemB {
	string OperationB1() {
		return "Subsystem B, Method B1\n";
	}

	string OperationB2() {
		return "Subsystem B, Method B2\n";
	}
};

struct SubsystemC {
	string OperationC1() {
		return "Subsystem C, Method C1\n";
	}
	
	string OperationC2() {
		return "Subsystem C, Method C2\n";
	}
};

class Facade {
	SubsystemA* a;
	SubsystemB* b;
	SubsystemC* c;
public:
	Facade() :
		a(new SubsystemA()),
		b(new SubsystemB()),
		c(new SubsystemC())
		{}

	void Operation1() {
		cout << ("Operation 1\n" +
			a->OperationA1() +
			a->OperationA2() +
			b->OperationB1());
	}
	void Operation2() {
		cout << ("Operation 2\n" +
			b->OperationB2() +
			c->OperationC1() +
			c->OperationC2());
	}
};

void facade_test();