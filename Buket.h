#ifndef _buket_h_
#define _buket_h_
#include <iostream>
#include <string>
#include "Cvet.h"
using namespace std;

class Buket {

private:
	struct Elem {
		Cvet data;
		Elem* next;
		int count;
		Elem(Cvet& cv) : data(cv), next(nullptr), count(1) {}
	};
	Elem* head = nullptr;
	Elem* tail = nullptr;
	int prodajnaCena=0;

public:
	Buket() = default;

	Buket(const Buket& b);

	Buket(Buket&& b);

	~Buket();

	Buket& dodajEl(Cvet& c);

	int izracunajZaradu() const;

	int izracunajNabavnu() const;

	int izracunajProdajnu() const;

	friend bool operator>(const Buket& b1, const Buket& b2);

	friend ostream& operator <<(ostream& , const Buket&);

};
#endif