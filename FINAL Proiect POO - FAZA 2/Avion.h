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
	string nr_zbor;
	//Pasager* p;


public:

	//constructor fara parametrii
	Avion();

	//constructor cu toti parametrii
	Avion(string, int, int, int, string);


	////constructor de copiere
	Avion(const Avion&);

	////operator 
	Avion& operator= (const Avion&);
	
	////istream 
	friend istream& operator>>(istream&, Avion&);

	//ostream
	friend ostream& operator<< (ostream&, const Avion&);

	//ofstream 
	friend ofstream& operator<< (ofstream&, const Avion&);

	//ifstream
	friend ifstream& operator>>(ifstream&, Avion&);

	//getteri

	string getNrInmatriculare();

	int getNrPasageri();

	int getCrew();

	int getAltitudineMax();

	string getNrZbor();


	//setteri

	void setNrInmatriculare(string);

	void setNrPasageri(int);

	void setCrew(int);

	void setAltitudineMax(int);

	void setNrZbor(string);









};

