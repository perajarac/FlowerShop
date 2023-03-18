#include "Cvet.h"

string Cvet::dohvNaziv() const
{
    return naziv;
}

int Cvet::dohvNabavna() const
{
    return nabavnaCena;
}

int Cvet::dohvProdajna() const
{
    return prodajnaCena;
}

int Cvet::Zarada() const
{
    return prodajnaCena - nabavnaCena;
}

bool operator==(const Cvet& c1, const Cvet& c2)
{
    return (c1.naziv == c2.naziv);
}

bool operator!=(const Cvet& c1, const Cvet& c2)
{
    return !(c1 == c2);
}

ostream& operator<<(ostream& it, const Cvet& c)
{
    return it << c.naziv;
}