#include "Buket.h"

Buket::Buket(const Buket& b)
{
	Elem* curr = b.head;
	Elem* n;
	while (curr) {

			n = new Elem(curr->data);
			if (!head) head = n;
			else {
				tail->next = n;
			}
			tail = n;
			curr = curr->next;

	}
}

Buket::Buket(Buket&& b)
{
	head = b.head;
	tail = b.tail;
	b.head = b.tail = nullptr;
}

Buket::~Buket()
{
	while (head) {
		Elem* curr = head;
		head = head->next;
		delete curr;
	}
}

Buket& Buket::dodajEl(Cvet& c) {
	if (!head) {
		head = tail = new Elem(c);
		return *this;
	}

	Elem* p = head;
	while (p && p->data != c)
		p = p->next;

	if (!p) {
		tail = tail->next = new Elem(c);
		return *this;
	}
	else {
		p->count++;
	}
	
	return *this;
}

int Buket::izracunajZaradu() const
{
	int zarada;
	return (zarada = izracunajProdajnu() - izracunajNabavnu());
}

int Buket::izracunajNabavnu() const
{
	int ukupnoN = 0;
	Elem* curr = head;
	while (curr) {
		ukupnoN += curr->data.dohvNabavna() * curr->count;
		curr = curr->next;
	}
	return ukupnoN;
}

int Buket::izracunajProdajnu() const
{
	int ukupnoP = 0;
	Elem* curr = head;
	while (curr) {
		ukupnoP += curr->data.dohvProdajna() * curr->count;
		curr = curr->next;
	}
	return ukupnoP;
}

bool operator>(const Buket& b1, const Buket& b2)
{
	return (b1.izracunajProdajnu() > b2.izracunajProdajnu());
}

ostream& operator <<(ostream& it, const Buket& b)
{
	it << "(";
	Buket::Elem* curr = b.head; 

	while (curr) {
		it << curr->data;
		if (curr->next) it << ", ";
		else it << ")";
		curr = curr->next;
	}
	it << b.izracunajProdajnu() << "RSD";
	return it;
}