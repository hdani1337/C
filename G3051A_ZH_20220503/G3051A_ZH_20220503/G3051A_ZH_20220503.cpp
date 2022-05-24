#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Egyesulet {
private:
	string nev;
	int* alapitasiEv;//dinamikus
public:
	Egyesulet();//alap�rtelmezett konstruktor
	Egyesulet(string nev, int alapitasiEv);//adattagos konstruktor
	Egyesulet(const Egyesulet& e) { nev = e.nev; alapitasiEv = new int; *alapitasiEv = *e.alapitasiEv; };
	~Egyesulet() { try { delete alapitasiEv; } catch (exception) { } };//destruktor

	/*getterek, setterek*/
	string getNev() { return nev; };
	int getAlapitasiEv() { return *alapitasiEv; };

	void setNev(string nev) { this->nev = nev; };
	void setAlapitasiEv(int alapitasiEv) { *this->alapitasiEv = alapitasiEv; };

	bool operator<(const Egyesulet &other) const;
};

class Uszo {
private:
	Egyesulet egyesulet;
	string nev;
	double *elsoSzintido;
	double *masodikSzintido;
	double orszagosSzintido;
public:
	Uszo(Egyesulet e, string n, double eSz, double mSz, double oSz) {
		elsoSzintido = new double;
		masodikSzintido = new double;
		egyesulet = e;
		nev = n;
		*elsoSzintido = eSz;
		*masodikSzintido = mSz;
		orszagosSzintido = oSz;
	};//norm�l konstruktor
	Uszo(const Uszo& uszo) {
		elsoSzintido = new double;
		masodikSzintido = new double;
		nev = uszo.nev;
		*elsoSzintido = *uszo.elsoSzintido;
		*masodikSzintido = *uszo.masodikSzintido;
		orszagosSzintido = uszo.orszagosSzintido;
		egyesulet = uszo.egyesulet;
	};//copy konstruktor
	~Uszo() {/* try { delete elsoSzintido; delete masodikSzintido; } catch (exception) {}*/ };//destruktor

	/*getterek, setterek*/
	Egyesulet getEgyesulet() { return egyesulet; };
	string getNev() { return nev; };
	double getElsoSzintido() { return *elsoSzintido; };
	double getMasodikSzintido() { return *masodikSzintido; };
	double getOrszagosSzintido() { return orszagosSzintido; };

	void setEgyesulet(Egyesulet e) { egyesulet = e; };
	void setNev(string n) { nev = n; };
	void setElsoSzintido(double i) { *elsoSzintido = i; };
	void setMasodikSzintido(double i) { *masodikSzintido = i; };
	void setOrszagosSzintido(double i) { orszagosSzintido = i; };

	double atlag() { return (*elsoSzintido + *masodikSzintido) / 2; };//�tlag
	bool teljesit() { return atlag() < orszagosSzintido; };//teljes�t�s
	double minimum() { return (*elsoSzintido > *masodikSzintido) ? *masodikSzintido : *elsoSzintido; }//kisebbet adja vissza
	double maximum() { return (*elsoSzintido > *masodikSzintido) ? *elsoSzintido : *masodikSzintido; }//nagyobbat adja vissza
};

Egyesulet::Egyesulet() {
	this->alapitasiEv = new int;
	*this->alapitasiEv = 2022;
	this->nev = "N�vtelen";
}

Egyesulet::Egyesulet(string nev, int alapitasiEv) {
	this->alapitasiEv = new int;
	*this->alapitasiEv = (alapitasiEv > 2022) ? 2022 : alapitasiEv;
	this->nev = nev;
}

bool Egyesulet::operator<(const Egyesulet &other) const {
	return (this->alapitasiEv < other.alapitasiEv);
}

int main()
{
	setlocale(0, "");

	string egyesuletNev;
	int egyesuletEv;

	string elsoNev;
	string masodikNev;

	double elsoElsoSzintido;
	double masodikElsoSzintido;

	double elsoMasodikSzintido;
	double masodikMasodikSzintido;

	double elsoOrszagosSzintido;
	double masodikOrszagosSzintido;

	cout << "K�rem az egyes�let nev�t: ";
	cin >> egyesuletNev;

	cout << "K�rem az egyes�let alap�t�si �v�t: ";
	cin >> egyesuletEv;

	cout << "K�rem az els� �sz� nev�t: ";
	cin >> elsoNev;

	cout << "K�rem az els� �sz� els� szintidej�t: ";
	cin >> elsoElsoSzintido;

	cout << "K�rem az els� �sz� m�sodik szintidej�t: ";
	cin >> elsoMasodikSzintido;

	cout << "K�rem az els� �sz� orsz�gos szintidej�t: ";
	cin >> elsoOrszagosSzintido;


	cout << "K�rem a m�sodik �sz� nev�t: ";
	cin >> masodikNev;

	cout << "K�rem a m�sodik �sz� els� szintidej�t: ";
	cin >> masodikElsoSzintido;

	cout << "K�rem a m�sodik �sz� m�sodik szintidej�t: ";
	cin >> masodikMasodikSzintido;


	cout << "K�rem a m�sodik �sz� orsz�gos szintidej�t: ";
	cin >> masodikOrszagosSzintido;

	Egyesulet e(egyesuletNev, egyesuletEv);

	Uszo uszo1(e,elsoNev,elsoElsoSzintido,elsoMasodikSzintido,elsoOrszagosSzintido);
	Uszo uszo2(e,masodikNev,masodikElsoSzintido,masodikMasodikSzintido,masodikOrszagosSzintido);

	cout << "Els� �sz� �tlaga: " << uszo1.atlag() << endl;
	cout << "M�sodik �sz� �tlaga: " << uszo2.atlag() << endl;

	cout << "Els� �sz� " << ((uszo1.teljesit()) ? "" : "nem ") << "teljes�tette az orsz�gos szintid�t." << endl;
	cout << "M�sodik �sz� " << ((uszo2.teljesit()) ? "" : "nem ") << "teljes�tette az orsz�gos szintid�t." << endl;
}
