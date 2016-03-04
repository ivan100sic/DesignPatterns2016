#pragma once

#include "flyweight.h"

StringFlyweight::operator string& () const {
	return FlyweightFactory::strs[id];
}

string FlyweightFactory::strs[256];

uint8_t FlyweightFactory::cnt = 0;

void flyweight_test() {
	auto x = FlyweightFactory::add("Ja");
	auto y = FlyweightFactory::add("Sam");
	auto z = FlyweightFactory::add("Ivan");

	for (string& i : { x, y, z }) {
		cout << i << endl;
	}
}