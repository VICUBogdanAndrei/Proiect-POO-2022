#define _CRT_SECURE_NO_WARNINGS
#include "Pasager.h"
#define n '\n'

Pasager::Pasager()
{
	/*this->nume = " ";
	this->prenume = " ";*/
	this->nume = new char[2];
	strcpy(this->nume, " ");
	this->prenume = new char[2];
	strcpy(this->prenume, " ");
	this->CNP = 0;
	this->nrBagaje = 0;
	this->seria = "XX";
	this->numar = "00";
}

//Pasager::Pasager(string nume, string prenume, long long CNP, int nrBagaje, string seria, string numar)
//{
//
//	this->nume = nume;
//	this->prenume = prenume;
//	this->CNP = CNP;
//	this->nrBagaje = nrBagaje;
//	this->seria = seria;
//	this->numar = numar;
//}

Pasager::Pasager(char* nume, char* prenume, long long CNP, int nrBagaje, string seria, string numar)
{
	char buffer1[200], buffer2[200];
	strcpy(buffer1, nume);
	this->nume = new char[strlen(buffer1) + 1];
	strcpy(this->nume, buffer1);

	//strcpy(buffer, '\0');
	strcpy(buffer2, prenume);
	this->prenume = new char[strlen(buffer2) + 1];
	strcpy(this->prenume, buffer2);

	this->CNP = CNP;
	this->nrBagaje = nrBagaje;
	this->seria = seria;
	this->numar = numar;
}

Pasager::Pasager(const Pasager& p)
{
	char buffer1[200], buffer2[200];
	strcpy(buffer1, p.nume);
	this->nume = new char[strlen(buffer1) + 1];
	strcpy(this->nume, buffer1);

	strcpy(buffer2, p.prenume);
	this->prenume = new char[strlen(buffer2) + 1];
	strcpy(this->prenume, buffer2);

	this->CNP = p.CNP;
	this->nrBagaje = p.nrBagaje;
	this->seria = p.seria;
	this->numar = p.numar;

}

Pasager& Pasager::operator=(const Pasager& p)
{
	if (this != &p) {
		char buffer1[200], buffer2[200];
		if (this->nume != NULL) delete[] this->nume;
		strcpy(buffer1, p.nume);
		this->nume = new char[strlen(buffer1) + 1];
		strcpy(this->nume, buffer1);

		if (this->prenume != NULL) delete[] this->prenume;
		strcpy(buffer2, p.prenume);
		this->prenume = new char[strlen(buffer2) + 1];
		strcpy(this->prenume, buffer2);

		this->CNP = p.CNP;
		this->nrBagaje = p.nrBagaje;
		this->seria = p.seria;
		this->numar = p.numar;
	}
	return *this;
	// // O: insert return statement here
}

int Pasager::varstaPasager(const Pasager& p)
{
	int nr = 14;
	int aux = p.CNP;
	while (nr != 7)
	{
		aux = aux / 10;
	}
	int zi_nastere = aux % 100;
	aux = aux / 100;
	int luna_nastere = aux % 100;
	aux = aux / 100;
	int an = aux % 100;
	aux = aux / 100;
	int an_nastere;
	if (aux / 10 == 0) {
		an_nastere = 1900 + an;
	}
	else an_nastere = 2000 + an;
	return 2022-an;
}

char* Pasager::getNume()
{
	return this->nume;
}

char* Pasager::getPrenume()
{
	return this->prenume;
}

long long Pasager::getCNP()
{
	return this->CNP;
}

int Pasager::getNrBagaje()
{
	return this->nrBagaje;
}

string Pasager::getSeria()
{
	return this->seria;
}

string Pasager::getNumar()
{
	return this->numar;
}

void Pasager::setNume(char* nume)
{
	if (nume != NULL)
	{
		char buffer[200];
		strcpy(buffer, nume);
		if (this->nume != NULL) delete[] this->nume;
		this->nume = new char[strlen(buffer) + 1];
		strcpy(this->nume, buffer);
	}
	else {
		if (this->nume != NULL) delete[] this->nume;
		this->nume = NULL;
	}
}

void Pasager::setPrenume(char* prenume)
{
	if (prenume != NULL)
	{
		char buffer[200];
		strcpy(buffer, prenume);
		if (this->prenume != NULL) delete[] this->prenume;
		this->prenume = new char[strlen(buffer) + 1];
		strcpy(this->prenume, buffer);
	}
	else {
		if (this->prenume != NULL) delete[] this->prenume;
		this->prenume = NULL;
	}
}

void Pasager::setCNP(long long CNP)
{
	if (CNP != 0)
	{
		int nr = 0;
		while (CNP)
		{
			nr++;
			CNP = CNP / 10;
		}
		if (nr == 13 && CNP != this->CNP)
			this->CNP = CNP;
	}
	else throw "ERROR: CNP INVALID!";
}

void Pasager::setNrBagaje(int nrBagaje)
{
	if (nrBagaje > 0 && nrBagaje != this->nrBagaje)
		this->nrBagaje = nrBagaje;
	else throw "ERROR: NUMAR DE BAGAJDE INVALID!";
}

void Pasager::setSeria(string seria)
{
	if (seria != "" && seria != this->seria)
		this->seria = seria;
	else throw "ERROR: SERIA DOCUMENTUKUI INVALIDA!";
}

void Pasager::setNumar(string numar)
{

	if (numar != "" && numar != this->numar)
		this->numar = numar;
	else throw "ERROR: NUMARUL DOCUMENTUKUI INVALIDA!";
}

Pasager::~Pasager()
{
	if (this->nume != NULL)
	{
		delete[] this->nume;
		this->nume = NULL;
	}
	if (this->prenume != NULL)
	{
		delete[] this->prenume;
		this->prenume = NULL;
	}
}


istream& operator>>(istream& input, Pasager& p)
{
	
	cout << "NUMELE PASAGERULUI: ";
	//input.ignore();
	char buffer1[200];
	input.getline(buffer1, 200);
	p.nume = new char[strlen(buffer1) + 1];
	strcpy(p.nume, buffer1);

	cout << "PRENUMELE PASAGERULUI: ";
	char buffer2[200];
	input.getline(buffer2, 200);
	p.prenume = new char[strlen(buffer2) + 1];
	strcpy(p.prenume, buffer2);

	cout << "CNP-UL PASAGERULUI: ";
	input >> p.CNP;
	cout << "NUMAR DE BAGAJE: ";
	input >> p.nrBagaje;
	cout << "SERIA DOCUMENTULUI:";
	input >> p.seria;
	cout << "NUMARUL DOCUMENTULUI: ";
	input >> p.numar;

	input.ignore();

	return input;
	// // O: insert return statement here
}

ostream& operator<<(ostream& output, const Pasager& p)
{
	output << "NUMELE PASAGERULUI: " << t << t << p.nume << '\n';;
	//if (p.nume == NULL) output << t << t << " " << n;
	//else output<< t << t << p.nume << '\n';
	output << "PRENUMELE PASAGERULUI: " << t << t << p.prenume << '\n';
	/*if (p.prenume == NULL) output << t << t << " " << n;
	else output << p.prenume << t << t << '\n';*/
	output << "CNP: " << t << t << t<< t<< p.CNP << '\n';
	output << "NUMAR BAGAJE: " << t<<t<<t<< p.nrBagaje << n;
	output << "SERIA DOCUMENT: " << t  << t << p.seria << n;
	output << "NUMAR DOCUMENT: " << t  << t << p.numar << n;

	return output;
	// // O: insert return statement here
}
