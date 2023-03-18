#ifndef _cvet_h_
#define _cvet_h_
#include <iostream>
using namespace std;
#include <string>

class Cvet {
private:
	string naziv;
	int nabavnaCena;
	int prodajnaCena;
public:

	Cvet(string n, int nc, int pc) : naziv(n), nabavnaCena(nc), prodajnaCena(pc) {}

	string dohvNaziv() const;
	int dohvNabavna() const;
	int dohvProdajna() const;

	friend bool operator==(const Cvet& c1, const Cvet& c2);
	friend bool operator!=(const Cvet& c1, const Cvet& c2);

	friend ostream& operator<<(ostream& it, const Cvet& c);

	int Zarada() const;
	
};
#endif