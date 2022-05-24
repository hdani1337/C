#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Haromszog {
private:
	int* a;
	int b;
	int c;
public:
	void setA(int _a) { *a = _a; };
	void setB(int _b) { b = _b; };
	void setC(int _c) { c = _c; };

	int* getA() { return a; };
	int getB() { return b; };
	int getC() { return c; };

	Haromszog();
	Haromszog(const Haromszog& h);
	Haromszog(int a, int b, int c);
	~Haromszog();
	double Heron();
};

Haromszog::Haromszog() {
	a = new int;
	*a = 0;
	b = 0;
	c = 0;
}

Haromszog::Haromszog(const Haromszog& h) {
	a = new int;
	*a = *h.a;
	b = h.b;
	c = h.c;
}

Haromszog::Haromszog(int _a, int _b, int _c) {
	a = new int;
	*a = _a;
	b = _b;
	c = _c;
}

Haromszog::~Haromszog() {
	delete a;
}

double Haromszog::Heron() {
	double s = (*a + b + c) / 2;
	double gyokAlatt = s * (s - *a) * (s - b) * (s - c);
	return pow(gyokAlatt, 0.5);
}

double heronSzamito(Haromszog h) {
	double s = (*h.getA() + h.getB() + h.getC()) / 2;
	double gyokAlatt = s * (s - *h.getA()) * (s - h.getB()) * (s - h.getC());
	return pow(gyokAlatt, 0.5);
}

int main()
{
	Haromszog statikusHaromszog;
	Haromszog* dinamikusHaromszog;
	dinamikusHaromszog = new Haromszog();

	ifstream oldalak("oldalak.txt");

	if (oldalak.is_open()) {
		while (!oldalak.eof()) {
			int beolvasott;
			oldalak >> beolvasott;
			statikusHaromszog.setA(beolvasott);
			oldalak >> beolvasott;
			statikusHaromszog.setB(beolvasott);
			oldalak >> beolvasott;
			statikusHaromszog.setC(beolvasott);

			oldalak >> beolvasott;
			dinamikusHaromszog->setA(beolvasott);
			oldalak >> beolvasott;
			dinamikusHaromszog->setB(beolvasott);
			oldalak >> beolvasott;
			dinamikusHaromszog->setC(beolvasott);
		}
	}

	setlocale(0, "");

	cout << "Statikus háromszög területe: " << statikusHaromszog.Heron() << endl;
	cout << "Dinamikus háromszög területe: " << dinamikusHaromszog->Heron() << endl;

	Haromszog nemSpecifikus(6, 3, 5);
	cout << "Nem specifikus háromszög területe külön függvénnyel számolva: " << heronSzamito(nemSpecifikus);
}