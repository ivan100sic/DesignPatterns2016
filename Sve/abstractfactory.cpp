#include "abstractfactory.h"

void abstractfactory_test() {
	Factory<AbsProduct> temp;
	temp.Register(0, new DerivedCreator<Product_A, AbsProduct>);
	temp.Register(1, new DerivedCreator<Product_B, AbsProduct>);

	AbsProduct* product = 0;

	product = temp.Create(0);
	cout << "Product_A: " << product->Get() << endl;
	delete product;

	product = temp.Create(1);
	cout << "Product_B: " << product->Get() << endl;
	delete product;
}