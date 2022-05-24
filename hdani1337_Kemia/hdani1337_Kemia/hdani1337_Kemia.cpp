#include <iostream>
#include <string>
using namespace std;

/*Elem osztály
Vegyjel(string)
Tömeg(double)
+=<< operátorok
+: vegyjeleket összevonja, tömegeket összeadja*/

class Elem {
public:
    string vegyjel;
    double tomeg;
    Elem();
    Elem(string v, double t);
    Elem operator+(const Elem &masik) const;
    Elem operator*(const int d);
    Elem& operator=(const Elem &masik);
    friend ostream& operator<<(ostream&stream, const Elem &masik);
    bool operator==(const Elem& masik) const;
    bool operator!=(const Elem& masik) const;
};

Elem::Elem() {
    //hidrogén
    vegyjel = "H";
    tomeg = 1.008;
}

Elem::Elem(string v, double t) {
    vegyjel = v;
    tomeg = t;
}

Elem Elem::operator+(const Elem& masik) const {
    Elem sum;
    sum.vegyjel = vegyjel + masik.vegyjel;
    sum.tomeg = tomeg + masik.tomeg;
    return sum;
}

Elem Elem::operator*(const int d) {
    Elem szorzott;
    szorzott.tomeg = d * tomeg;
    szorzott.vegyjel = to_string(d) + vegyjel;
    return szorzott;
}

Elem& Elem::operator=(const Elem& masik) {
    vegyjel = masik.vegyjel;
    tomeg = masik.tomeg;
    return *this;
}

ostream& operator<<(ostream& stream, const Elem& masik) {
    stream << "Vegyjel: " << masik.vegyjel << ", tomege: " << masik.tomeg << endl;
    return stream;
}

bool Elem::operator==(const Elem& masik) const {
    return tomeg == masik.tomeg;
}

bool Elem::operator!=(const Elem& masik) const {
    return !(*this == masik);
}

int main()
{
    Elem oxigen("O", 16);
    Elem hidrogen;
    Elem hidroxid = hidrogen + oxigen;
    Elem haromHidroxid = hidroxid * 3;
    Elem viz = hidrogen * 2 + oxigen;
    Elem masikViz = hidrogen + hidrogen + oxigen;
    cout << oxigen;
    cout << hidrogen;
    cout << hidroxid;
    cout << haromHidroxid;
    cout << (viz==masikViz);
}