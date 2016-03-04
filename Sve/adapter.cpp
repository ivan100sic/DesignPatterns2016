#include "adapter.h"

#include <vector>

void adapter_test() {
	vector<IPrintable*> printeri;
	printeri.push_back(new PrintableAdapter<Printer>(new Printer()));
	printeri.push_back(new PrintableAdapter<Fax>(new Fax()));
	printeri.push_back(new CompliantPrinter());
	
	for (auto printer : printeri) printer->print("Hello, world!");

	for (auto printer : printeri) delete printer;
}

void Printer::print() const {
	cout << "Print internal PrintJob" << endl;
}

void Fax::fax(const char * str) const {
	cout << "Fax & Print " << str << endl;
}

void CompliantPrinter::print(const char * str) const {
	cout << str << endl;
}
