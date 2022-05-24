#include <iostream>
#include <fstream>

using namespace std;

class Haz {
private:
	/*ADATTAG*/
	string nev;
public:
	/*KONSTRUKTOROK*/
	Haz() {};
	Haz(string nev) { this->nev = nev; };

	/*GETTER-SETTER*/
	string getNev() { return nev; };
	void setNev(string nev) { this->nev = nev; };
};

class Bank : public Haz {
private:
	/*DINAMIKUS ADATTAG*/
	int* toke;
public:
	/*KONSTRUKTOROK*/
	Bank() { 
		this->toke = new int; 
		ifstream fajl("toke.txt");
		if (fajl.is_open()) fajl >> *toke;
	};
	Bank(int toke) { 
		this->toke = new int; 
		*this->toke = toke; 
	};
	Bank(const Bank& bank) {
		toke = new int;
		*toke = *bank.toke;
	};

	/*DESTRUKTOR*/
	~Bank() { delete toke; };

	/*GETTER-SETTER*/
	int getToke() { return *toke; };
	void setToke(int toke) { *this->toke = toke; };

	/*OPERÁTORTÚLTERHELÉS*/
	bool operator<(const Bank& masik) const { return *this->toke < *masik.toke; };//<
	bool operator<=(const Bank& masik) const { return *this->toke <= *masik.toke; };//<=
	bool operator>(const Bank& masik) const { return *this->toke > *masik.toke; };//>
	bool operator>=(const Bank& masik) const { return *this->toke >= *masik.toke; };//>=
	Bank operator+(const Bank& masik) const { Bank temp; temp.setToke(*this->toke + *masik.toke); return temp; };//+
	Bank& operator=(const Bank& masik) { *this->toke = *masik.toke;  return *this; };//=
	friend ostream& operator<<(ostream& stream, Bank& bank) { stream << bank.getNev() << ": " << *bank.toke << endl; return stream; };//<<
};

int main()
{
	Bank MKB;
	Bank BB(3000);

	MKB.setNev("MKB");
	BB.setNev("Budapest Bank");

	setlocale(0, "");

	cout << "MKB tõke: " << MKB.getToke() << endl;
	cout << "BB tõke: " << BB.getToke() << endl;

	cout << "MKB < BB: " << (MKB < BB) << endl;
	cout << "MKB <= BB: " << (MKB <= BB) << endl;
	cout << "MKB > BB: " << (MKB > BB) << endl;
	cout << "MKB >= BB: " << (MKB >= BB) << endl;

	cout << "MKB = MKB + BB" << endl;
	MKB = MKB + BB;
	cout << "MKB tõke: " << MKB.getToke() << endl;

	cout << MKB;
}