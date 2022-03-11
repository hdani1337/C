#include "pch.h"
#include "Haromszog.h"
#include "math.h"
#include <iostream>


int Haromszog::kerulet() {
	return a + b + c;
}

int Haromszog::terulet() {
	int s = kerulet() / 2;
	return sqrt(s*(s - a)*(s - b)*(s - c));
}

bool Haromszog::helyes() {
	return (a + b > c) && (a + c > b) && (b + c > a);
}

void Haromszog::kiir() {
	std::cout << terulet() << " a ter�let, " << kerulet() << " a ker�let, " << ((helyes()) ? "szerkeszthet�.\n" : "nem szerkeszthet�.\n");
}