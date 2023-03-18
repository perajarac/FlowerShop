#include <iostream>
#include "Cvet.h"
#include "Buket.h"
#include "Cvecara.h"
using namespace std;

int main() {

	cout << "TEST:" << endl << endl;

	Cvet c1("Mika", 300, 200);
	Cvet c2("Laki", 300, 600);
	Cvet c3("Peki", 300, 1000);
	Cvet c4("Zivan", 100, 180);
	Cvet c5("Mikica", 200, 500);
	Cvet c6("Laki", 700, 720);
	Cvet c7("Tale", 100, 350);

	cout << "Provera da li su dva cveta ista(0 ako nisu, 1 ako jesu) i ispisa cveta: ";
	cout << ", a cvetovi 2 i 6 su isti: " << (c2 == c6) << ", a cvetovi 2 i 1 razlicti: " << (c1 == c2) << endl;
	cout << "Ispis cveta:" << c2<< endl << endl;


	Buket b1;
	b1.dodajEl(c1).dodajEl(c2).dodajEl(c2);
	cout << "Provera ispisa buketa:" << endl << b1 << endl; //provera da li stampa duple cvetove

	Buket b2; 
	b2.dodajEl(c4).dodajEl(c2).dodajEl(c2);;
	cout << b2 << endl;
	cout << "Provera preklapanja operatora >, ako je levi operand veci vraca 1, u suprotnom 0: " << (b1 > b2) << endl << endl;

	Buket b3;
	b3.dodajEl(c6);

	Buket b4;
	b4.dodajEl(c5).dodajEl(c4);

	Buket b5;
	b5.dodajEl(c7);

	Cvecara Mikica;
	Mikica.dodajEl(b1).dodajEl(b3); //provera da li dodaje buket koji se ignorise
	Mikica.dodajEl(b2);//dodavanje elemenata u cvecaru
	Mikica.UkloniElement(0); //1.provera da li skida sa prvog indeksa
	cout << "Ispis cvecare posle uklanjanja elementa sa zadatim indeksom i provera da li se dodao nevazeci element: " << endl <<Mikica << endl << endl;   //2.provera da li skida sa prvog indeksa

	Cvecara Maxi;
	Maxi.dodajEl(b1).dodajEl(b2).dodajEl(b5).dodajEl(b3);
	
	cout << "Pre brisanja:" << endl << endl << Maxi << endl;
	Maxi.UkloniElement(1); //uklanja sa random pozicije
	cout <<endl << "Posle brisanja:" << endl << endl << Maxi << endl;

	cout << endl << endl << "KRAJ TEST";
}