#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Telepules {
private:
	string varos;
	string utca;
public:
	Telepules(string v, string u) { varos = v; utca = u; };
	Telepules() {};
	string getVaros() { return varos; }
	string getUtca() { return utca; }
	void setVaros(string v) { varos = v; };
	void setUtca(string u) { utca = u; };
};

class Lakas {
public:
	Telepules t;
	double *terulet;
	int *szoba;
	double berletiDij() { return (t.getVaros() == "Budapest") ? *terulet * 2500 : *terulet * 1500; };
	Lakas(Telepules t) { this->t = t; };
	Lakas(Telepules t, int szoba, double terulet);
	~Lakas();
};

Lakas::Lakas(Telepules t, int szoba, double terulet) {
	this->t = t; 
	this->szoba = new int;
	this->terulet = new double;
	*(this->szoba) = szoba;  
	*(this->terulet) = terulet;
}

Lakas::~Lakas() {
	delete terulet;
	delete szoba;
}

class Taxi {
	//rendszám, gyártó, típus, *indulás, *érkezés
	//bevétel 1km után 650ft
	//szöveg 0-50ezer alacsony, 50ezer-100ezer átlagos, 100ezer+ magas
private:
	string rendszam;
	string gyarto;
	string tipus;
	int *indulas;
	int *erkezes;
public:
	Taxi(string rendszam, string gyarto, string tipus, int indulas, int erkezes);
	~Taxi();
	int bevetel();
	string szoveg();
};

Taxi::Taxi(string rendszam, string gyarto, string tipus, int indulas, int erkezes) {
	this->rendszam = rendszam;
	this->gyarto = gyarto;
	this->tipus = tipus;

	this->indulas = new int;
	this->erkezes = new int;

	*(this->indulas) = indulas;
	*(this->erkezes) = erkezes;
}

Taxi::~Taxi() {
	delete indulas;
	delete erkezes;
}

int Taxi::bevetel() {
	return (*erkezes - *indulas) * 650;
}

string Taxi::szoveg() {
	return (bevetel() <= 50000) ? "alacsony" : (bevetel() <= 100000) ? "kozepes" : "magas";
}

int main()
{
	Telepules Budapest("Budapest","Blaha Lujza tér");
	Telepules Nagykanizsa("Nagykanizsa","Fõ utca");

	Lakas *pestiLakas = new Lakas(Budapest, 3, 60);
	
	//cout << "Budapesti lakas: " << (*pestiLakas).berletiDij() << endl;
	//cout << "Nagykanizsai lakas: " << kanizsaiLakas.berletiDij() << endl;

	Taxi Suzuki("ABC-123", "Suzuki", "Swift", 0, 500);
	cout << Suzuki.szoveg();
}
