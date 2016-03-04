#pragma once

template<class T>
struct IMemorija {
	virtual void dodaj(T) = 0;
	virtual T uzmi() = 0;
	virtual ~IMemorija() {}
};

template<class T>
struct Cvor {
	T info;
	Cvor<T>* next;
	Cvor(T info, Cvor<T>* next) : info(info), next(next) {}
};

template<class T>
class LancanaLista : public IMemorija<T> {
	Cvor<T>* glava;
public:
	bool jePrazna() {
		return glava == 0;
	}

	LancanaLista() : glava(0) {}

	void dodaj(T x) {
		glava = new Cvor<T>(x, glava);
	}

	T uzmi() {
		T tmp = glava->info;
		auto p = glava;
		glava = glava->next;
		delete p;
		return tmp;
	}

	~LancanaLista() {
		while (glava) {
			auto p = glava;
			glava = glava->next;
			delete p;
		}
	}
};

template<class T>
class Niz : public IMemorija<T> {
	T* data;
	int top;
	int kapac;
	static const int INIT_SIZE = 2;

	void povecaj() {
		T* p = new T[kapac*2];
		for (int i = 0; i < top; i++) {
			p[i] = data[i];
		}
		kapac *= 2;
		delete[] data;
		data = p;
	}
public:
	Niz() : data(new T[INIT_SIZE]), top(0), kapac(INIT_SIZE) {}

	void dodaj(T x) {
		if (top == kapac) povecaj();
		data[top++] = x;
	}

	T uzmi() {
		return data[--top];
	}

	~Niz() {
		delete[] data;
	}
};

// I sada mozemo da implementiramo stek

template<class T, template<typename> class Memorija = Niz>
class Stek {
	Memorija<T> mem;
public:
	void push(T x) {
		mem.dodaj(x);
	}

	T pop() {
		return mem.uzmi();
	}
};

void bridge_test();