#pragma once

#include <iostream>
using namespace std;

template<class T>
class SmartPtr {
	T* ptr;
	size_t* br;

	void detach() {
		--*br;
		if (*br == 0) {
			delete ptr;
			delete br;
		}
	}

public:

	SmartPtr(T* ptr) : ptr(ptr), br(new size_t(1)) {}

	SmartPtr(const SmartPtr& other) : ptr(ptr), br(br) {
		++*br;
	}

	SmartPtr& operator= (const SmartPtr& other) {
		if (this != &other) {
			detach();
			ptr = other.ptr;
			br = other.br;
			++*br;
		}
		return *this;
	}

	T* operator-> () { return ptr; }
	T& operator* () { return *ptr; }
	const T* operator-> () const { return ptr; }
	const T& operator* () const { return *ptr; }

	~SmartPtr() {
		detach();
	}

};

struct Proxyn {
	Proxyn(int x) {
		cout << "Konstruktor " << x << "\n";
	}

	~Proxyn() {
		cout << "Destruktor\n";
	}
};

void proxy_test();