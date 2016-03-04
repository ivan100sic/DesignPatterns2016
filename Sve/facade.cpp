#include "facade.h"

#include <iostream>
using namespace std;

void facade_test() {
	cout << "Pozivam ostale funkcije..." << endl;
	Facade f;
	f.Operation1();
	f.Operation2();
}
