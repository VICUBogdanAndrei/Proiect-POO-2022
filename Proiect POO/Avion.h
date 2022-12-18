#pragma once
#define n '\n'
#include "Zbor.h"
#include <string>

using namespace std;

class Avion
{
private:
	string nrInmatriculare;
	int nrPasageri;
	int crew;
	int altitudineMax;
	Zbor z;
	//Pasager* p;


public:

	//constructor fara parametrii
	Avion();

	//constructor cu toti parametrii
	Avion(string, int, int, int, Zbor);


	////constructor de copiere
	Avion(const Avion&);

	////operator 
	Avion& operator= (const Avion&);
	
	////istream 
	friend istream& operator>>(istream&, Avion&);

	//ostream
	friend ostream& operator<< (ostream&, const Avion&);

	//getteri

	string getNrInmatriculare();

	int getNrPasageri();

	int getCrew();

	int getAltitudineMax();

	Zbor getZ();


	//setteri

	void setNrInmatriculare(string);

	void setNrPasageri(int);

	void setCrew(int);

	void setAltitudineMax(int);

	void setZ(Zbor);
	









};

