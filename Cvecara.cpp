#include "Cvecara.h"
#include <iostream>
using namespace std;

Cvecara::Cvecara(const Cvecara& c)
{
	Node* curr = c.head;
	Node* n;
	while (curr) {
		n = new Node(curr->data);
		if (!head) head = n;
		else {
			tail->next = n;
		}
		tail = n;
		curr = curr->next;
	}
}

Cvecara::Cvecara(Cvecara&& c)
{
	head = c.head;
	tail = c.tail;
	c.tail = c.head = nullptr;
}

Cvecara::~Cvecara()
{
	while (head) {
		Node* curr = head;
		head = head->next;
		delete curr;
	}
}

Cvecara& Cvecara::UkloniElement(int a) {
	if (!head) return *this;
	int br = 0;
	Node* temp = head;
	Node* curr = head->next;
	if (a == 0) {
		head = curr;
		zarada += temp->data.izracunajProdajnu();
		delete temp;
	}
	else {
		while (curr && br < a-1) {
			temp = curr;
			curr = curr->next;
			br++;
		}
		if (!curr)
			return *this;

		temp->next = curr->next;
		zarada += curr->data.izracunajProdajnu();
		delete curr;
	}
	return *this;	
}

Cvecara& Cvecara::dodajEl(Buket b)
{
	if (0.8 * b.izracunajProdajnu() >= b.izracunajNabavnu()) {
		Node* n = new Node(b);
		int key = b.izracunajProdajnu();
		if (!head) {
			head = n;
			zarada -= n->data.izracunajNabavnu();
		}
		else if (head->data.izracunajProdajnu() > key) {
			n->next = head;
			head = n;
			zarada -= n->data.izracunajNabavnu();
		}
		else {
			Node* temp = head;
			Node* curr = head->next;
			while (curr != nullptr && curr->data.izracunajProdajnu() > key) {
				temp = curr;
				curr = curr->next;
			}
			temp->next = n;
			n->next = curr;
			zarada -= n->data.izracunajNabavnu();
		}
	}
	return *this;
}

ostream& operator<<(ostream& it, const Cvecara& c)
{
	it << "zarada=" << c.dohvZarada() << "RSD" << endl;
	Cvecara::Node* curr = c.head;
	while (curr) {
		it << curr->data;
		if (curr->next) it << endl;	
		curr = curr->next;
		//if (curr->next == nullptr) return it << curr->data;
	}
	return it;
}