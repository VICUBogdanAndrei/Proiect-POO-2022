#define _CRT_SECURE_NO_WARNINGS
#define n '\n'

#include "Avion.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Avion::Avion()
{
	this->nrInmatriculare = "";
	this->nrPasageri = 0;
	this->crew = 0;
	this->altitudineMax = 30000;
	this->nr_zbor = "";

}

Avion::Avion(string nrInmatriculare, int nrPasageri, int crew, int altitudineMax, string nr_zbor)
{
	this->nrInmatriculare = nrInmatriculare;
	this->nrPasageri = nrPasageri;
	this->crew = crew;
	this->altitudineMax = altitudineMax;
	this->nr_zbor = nr_zbor;
}

Avion::Avion(const Avion& a)
{
	this->nrInmatriculare = a.nrInmatriculare;
	this->nrPasageri = a.nrPasageri;
	this->crew = a.crew;
	this->altitudineMax = a.altitudineMax;
	this->nr_zbor = a.nr_zbor;
}

Avion& Avion::operator=(const Avion& a)
{
	if (this != &a)
	{
		this->nrInmatriculare = a.nrInmatriculare;
		this->nrPasageri = a.nrPasageri;
		this->crew = a.crew;
		this->altitudineMax = a.altitudineMax;
		this->nr_zbor = a.nr_zbor;
	}
	return *this;
}

string Avion::getNrInmatriculare()
{
	return this->nrInmatriculare;
}

int Avion::getNrPasageri()
{
	return this->nrPasageri;
}

int Avion::getCrew()
{
	return this->crew;
}

int Avion::getAltitudineMax()
{
	return this->altitudineMax;
}

string Avion::getNrZbor()
{
	return this->nr_zbor;
}



void Avion::setNrInmatriculare(string nrInmatriculare)
{
	if (nrInmatriculare != "" && this->nrInmatriculare != nrInmatriculare)
	{
		this->nrInmatriculare = nrInmatriculare;
	}
	else throw"ERROR: NUMAR INMATRICULARE INVALID!";
}

void Avion::setNrPasageri(int nrPasager)
{
	if (nrPasager > 0 && nrPasager != this->nrPasageri)
	{
		this->nrPasageri = nrPasager;
	}
	else throw "ERROR: NUMAR PASAGERI INVALID!";
}

void Avion::setCrew(int crew)
{
	if (crew > 0 && crew != this->crew)
	{
		this->crew = crew;
	}
	else throw "ERROR: CREW INVALID!";
}

void Avion::setAltitudineMax(int altitudineMax)
{
	if (altitudineMax > 0 && altitudineMax != this->altitudineMax)
	{
		this->altitudineMax = altitudineMax;
	}
	else throw "ERROR: ALTITUDINE MAXIMA INVALIDA!";
}

void Avion::setNrZbor(string nr_zbor)
{
	if (nr_zbor != "" && nr_zbor != this->nr_zbor && nr_zbor.length() == 6)
		this->nr_zbor = nr_zbor;
	else throw "ERROR: NUMARUL ZBORULUI ESTE INVALID!";
}




istream& operator>>(istream& input, Avion& a)
{
	cout << "NUMAR INMATRICULARE: ";
	input >> a.nrInmatriculare;
	cout << "CAPACITATE PASAGERI: ";
	input >> a.nrPasageri;
	cout << "MEMBRI CREW: ";
	input >> a.crew;
	cout << "ALTITUDINEA MAXIMA: ";
	input >> a.altitudineMax;
	cout << "NUMARUL ZBORULUI: ";
	input >> a.nr_zbor;


	return input;
	// // O: insert return statement here
}

ostream& operator<<(ostream& consola, const Avion& a)
{
	consola << "NUMAR INMATRICULARE: " << '\t' << '\t' << a.nrInmatriculare << '\n';
	consola << "CAPACITATE PASAGERI:" << '\t' << '\t' << a.nrPasageri << '\n';
	consola << "MEMBRI CREW: " << '\t' << '\t' << '\t' << a.crew << '\n';
	consola << "ALTITUDINEA MAXIMA: " << '\t' << '\t' << a.altitudineMax << '\n';
	consola << "NUMARUL ZBORULUI: " << t << t << a.nr_zbor << n;

	return consola;
	// // O: insert return statement here
}

ofstream& operator<<(ofstream& outputfile, const Avion& a)
{
	//outputfile << "NUMAR INMATRICULARE AVION  NUMAR MAXIM PASAGERI  MEMBRI CREW  ALTITUDINE MAXIMA  NUMAR ZBOR";
	outputfile << a.nrInmatriculare << " " << a.nrPasageri << " " << a.crew << " " << a.altitudineMax << " " << a.nr_zbor<<n;


	return outputfile;
	// // O: insert return statement here
}

ifstream& operator>>(ifstream& inputfile, Avion& a)
{
	inputfile >> a.nrInmatriculare;
	inputfile >> a.nrPasageri;
	inputfile >> a.crew;
	inputfile >> a.altitudineMax;
	inputfile >> a.nr_zbor;

	return inputfile;
	// // O: insert return statement here
}
