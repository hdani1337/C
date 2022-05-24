#include <iostream>
#include <fstream>

using namespace std;

class Mikroba {
protected:
	int* meret;
public:
	Mikroba() { meret = new int; *meret = 0; };
	~Mikroba() { delete meret; };
};

class Antibiotikus : public Mikroba {
private:
	int* termelesiSebesseg;
public:
	/*GETTER SETTER*/
	void setTermelesiSebesseg(int s) { termelesiSebesseg = new int; *termelesiSebesseg = s; };
	int getTermelesiSebesseg() { return *termelesiSebesseg; };
	/*KONSTRUKTOROK, DESTRUKTOR*/
	Antibiotikus() { termelesiSebesseg = new int; *termelesiSebesseg = 5; };
	Antibiotikus(int s){
		termelesiSebesseg = new int; *termelesiSebesseg = s; 
		ifstream fajl("mikroba.txt");
		if (fajl.is_open()) fajl >> *meret;
		else cout << "mikroba.txt nem talalhato.";
	}
	~Antibiotikus() { delete termelesiSebesseg; };
	Antibiotikus(const Antibiotikus& anti) {
		termelesiSebesseg = new int;
		*termelesiSebesseg = *anti.termelesiSebesseg;
		*meret = *anti.meret;
	};
	/*OVERLOAD*/
	Antibiotikus operator*(const Antibiotikus& masik) const { 
		Antibiotikus temp; 
		temp.setTermelesiSebesseg((* this->termelesiSebesseg) * (*masik.termelesiSebesseg));
		*temp.meret = (*meret) * (*masik.meret);
		return temp;
	};
	Antibiotikus& operator=(const Antibiotikus& masik) { 
		*this->termelesiSebesseg = *masik.termelesiSebesseg;
		*this->meret = *masik.meret;
		return *this; };
};

class Patogen : public Mikroba {
private:
	int fertozoKepesseg;
public:
	/*GETTER SETTER*/
	void setFertozoKepessegg(int s) { fertozoKepesseg = s; };
	int getFertozoKepesseg() { return fertozoKepesseg; };
	/*KONSTRUKTOROK*/
	Patogen() { fertozoKepesseg = 50; };
	Patogen(int mer, int fert = 100) { *meret = mer; fertozoKepesseg = fert; };
	Patogen(const Patogen& pati) {
		fertozoKepesseg = pati.fertozoKepesseg;
		*meret = *pati.meret;
	};
	/*OVERLOAD*/
	Patogen operator+(const Patogen& masik) const {
		Patogen temp;
		temp.setFertozoKepessegg(this->fertozoKepesseg + masik.fertozoKepesseg);
		*temp.meret = (*meret) * (*masik.meret);
		return temp;
	};
	Patogen& operator=(const Patogen& masik) {
		this->fertozoKepesseg = masik.fertozoKepesseg;
		*this->meret = *masik.meret;
		return *this;
	};
};

int main()
{
	Antibiotikus PS;
	Patogen SA(100, 100);

	cout << "PS: " << PS.getTermelesiSebesseg() << endl;
	cout << "PS = PS*10 elvegzese" << endl;
	PS = PS * 10;
	cout << "PS uj eredmenye: " << PS.getTermelesiSebesseg() << endl;

	cout << endl;

	cout << "SA: " << SA.getFertozoKepesseg() << endl;
	cout << "SA = SA+SA elvegzese" << endl;
	SA = SA + SA;
	cout << "SA uj eredmenye: " << SA.getFertozoKepesseg() << endl;
}