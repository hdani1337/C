#include "pch.h"
#include <iostream>
#include "Haromszog.h"

using namespace std;

class Teglalap {
public: int a;
public: int b;

public: int kerulet() {
		return 2*(a+b);
	}

public:	int terulet() {
		return a * b;
	}
	
public: void kiir() {
	cout << "A téglalap oldalai " << a << " és " << b << ", a kerülete " << kerulet() << ", a területe pedig " << terulet() << "." << endl;
}
};

class Masodfoku {
public: int a;
public: int b;
public: int c;

public: int diszkriminans();
public: int megoldasokSzama();

public: double x_1();
public: double x_2();
};

int Masodfoku::diszkriminans() {
	return (b*b) - (4 * a*c);
}

int Masodfoku::megoldasokSzama() {
	return (diszkriminans() > 0) ? 2 : (diszkriminans() == 0) ? 1 : -1;
}

double Masodfoku::x_1() {
	return (-b + sqrt(diszkriminans())) / (2 * a);
}

double Masodfoku::x_2() {
	return (-b - sqrt(diszkriminans())) / (2 * a);
}

int main()
{
	setlocale(0, "");
	Teglalap t;
	t.a = 5;
	t.b = 10;
	t.kiir();

	Masodfoku m;
	m.a = 1;
	m.b = -3;
	m.c = 2;

	cout << m.diszkriminans() << " " << m.megoldasokSzama() << endl;
	cout << m.x_1() << " " << m.x_2() << endl;

	Haromszog h;
	h.a = 5;
	h.b = 6;
	h.c = 8;
	h.kiir();
}