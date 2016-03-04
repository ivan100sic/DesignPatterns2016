#include "abstractfactory.h"
#include "singleton.h"
#include "factorymethod.h"
#include "prototype.h"
#include "adapter.h"
#include "builder.h"
#include "bridge.h"
#include "composite.h"
#include "decorator.h"
#include "facade.h"
#include "proxy.h"
#include "flyweight.h"
#include "chainofresponsibility.h"
#include "command.h"
#include "observer.h"
#include "mediator.h"
#include "visitor.h"
#include "memento.h"

int main() {
	abstractfactory_test();
	singleton_test();
	factorymethod_test();
	prototype_test();
	adapter_test();
	builder_test();
	bridge_test();
	composite_test();
	decorator_test();
	facade_test();
	proxy_test();
	flyweight_test();
	chainofresponsibility_test();
	command_test();
	observer_test();
	mediator_test();
	visitor_test();
	memento_test();

	system("pause");
	return 0;
}