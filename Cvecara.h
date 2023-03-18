#ifndef _cvecara_h_
#define _cvecara_h_
#include <iostream>
#include "Buket.h"
using namespace std;

class Cvecara {
private:
	int zarada = 1000;
public:
	struct Node {
		Buket data;
		Node* next;
		Node(Buket& b) : data(b), next(nullptr) {}
	};
	Node* head = nullptr; Node* tail = nullptr;
public:

	int dohvZarada() const { return zarada; }

	Cvecara() = default;

	Cvecara(const Cvecara& c);

	Cvecara(Cvecara&& c);

	~Cvecara();

	Cvecara& dodajEl(Buket b);
	
	Cvecara& UkloniElement(int a);

	friend ostream& operator<<(ostream& it, const Cvecara& c);
};


#endif
