#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Egyesulet {
private:
	string nev;
	int* alapitasiEv;//dinamikus
public:
	Egyesulet();//alapértelmezett konstruktor
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
	};//normál konstruktor
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

	double atlag() { return (*elsoSzintido + *masodikSzintido) / 2; };//átlag
	bool teljesit() { return atlag() < orszagosSzintido; };//teljesítés
	double minimum() { return (*elsoSzintido > *masodikSzintido) ? *masodikSzintido : *elsoSzintido; }//kisebbet adja vissza
	double maximum() { return (*elsoSzintido > *masodikSzintido) ? *elsoSzintido : *masodikSzintido; }//nagyobbat adja vissza
};

Egyesulet::Egyesulet() {
	this->alapitasiEv = new int;
	*this->alapitasiEv = 2022;
	this->nev = "Névtelen";
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

	cout << "Kérem az egyesület nevét: ";
	cin >> egyesuletNev;

	cout << "Kérem az egyesület alapítási évét: ";
	cin >> egyesuletEv;

	cout << "Kérem az elsõ úszó nevét: ";
	cin >> elsoNev;

	cout << "Kérem az elsõ úszó elsõ szintidejét: ";
	cin >> elsoElsoSzintido;

	cout << "Kérem az elsõ úszó második szintidejét: ";
	cin >> elsoMasodikSzintido;

	cout << "Kérem az elsõ úszó országos szintidejét: ";
	cin >> elsoOrszagosSzintido;


	cout << "Kérem a második úszó nevét: ";
	cin >> masodikNev;

	cout << "Kérem a második úszó elsõ szintidejét: ";
	cin >> masodikElsoSzintido;

	cout << "Kérem a második úszó második szintidejét: ";
	cin >> masodikMasodikSzintido;


	cout << "Kérem a második úszó országos szintidejét: ";
	cin >> masodikOrszagosSzintido;

	Egyesulet e(egyesuletNev, egyesuletEv);

	Uszo uszo1(e,elsoNev,elsoElsoSzintido,elsoMasodikSzintido,elsoOrszagosSzintido);
	Uszo uszo2(e,masodikNev,masodikElsoSzintido,masodikMasodikSzintido,masodikOrszagosSzintido);

	cout << "Elsõ úszó átlaga: " << uszo1.atlag() << endl;
	cout << "Második úszó átlaga: " << uszo2.atlag() << endl;

	cout << "Elsõ úszó " << ((uszo1.teljesit()) ? "" : "nem ") << "teljesítette az országos szintidõt." << endl;
	cout << "Második úszó " << ((uszo2.teljesit()) ? "" : "nem ") << "teljesítette az országos szintidõt." << endl;
}
