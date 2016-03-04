#pragma once

#include <iostream>
using namespace std;

/* Lazin cuveni primer */

struct IPrintable {
	virtual void print(const char*) const = 0;
	virtual ~IPrintable() {}
};

struct Printer {
	void print() const {
		cout << "Print internal PrintJob" << endl; 
	}
};

struct Fax {
	void fax(const char* str) const {
		cout << "Fax & Print " << str << endl;
	}
};

struct CompliantPrinter : public IPrintable {
	virtual void print(const char* str) const {
		cout << str << endl;
	}
};

template<class T>
class PrintableAdapter : public IPrintable {
public:
	PrintableAdapter(T* ptr) : ptr(ptr) {}

	virtual void print(const char* str) const {
		adapt(ptr, str);
	}

	virtual ~PrintableAdapter() {
		delete ptr;
	}
private:

	template<class U>
	static void adapt(U* t, const char* str) {
		t->print(str);
	}

	template<>
	static void adapt<Printer>(Printer* t, const char*) {
		t->print();
	}

	template<>
	static void adapt<Fax>(Fax* t, const char* str) {
		t->fax(str);
	}

	T* ptr;
};

void adapter_test();