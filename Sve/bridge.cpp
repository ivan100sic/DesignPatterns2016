#include "bridge.h"

#include <iostream>
using namespace std;

void bridge_test() {
	Stek<int> stek;
	Stek<int, LancanaLista> stek_lista;
	for (int i = 0; i < 5; i++) {
		stek.push(i);
		stek_lista.push(i);
	}
	for (int i = 0; i < 5; i++) {
		cout << stek.pop() << ' ' << stek_lista.pop() << endl;
	}
}