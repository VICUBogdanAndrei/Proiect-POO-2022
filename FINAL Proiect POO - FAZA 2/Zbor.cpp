#define n '\n'

#include <iostream>
#include <iomanip>
#include <string>
#include "Zbor.h"

using namespace std;

int Zbor::contor = 10000;

Zbor::Zbor() : nrZbor("000000")
{
	this->numeCompanie = "";
	this->origine = "";
	this->destinatie = "";
	this->distanta = 0;
	this->durata = 0;
	this->time.ora = 0;
	this->time.minut = 0;
	this->pretMin = 0;
	this->pretMax = 0;
}
	

Zbor::Zbor(string nrZbor, string numeCompanie, string origine, string destinatie, float distanta, int durata, int ora, int minut, float pretMin, float pretMax) : nrZbor(nrZbor)
{
	this->numeCompanie = numeCompanie;
	this->origine = origine;
	this->destinatie = destinatie;
	this->distanta = distanta;
	this->durata = durata;
	this->time.ora = ora;
	this->time.minut = minut;
	this->pretMin = pretMin;
	this->pretMax = pretMax;

}

Zbor::Zbor(const Zbor& z) :nrZbor(z.nrZbor)
{
	this->numeCompanie = z.numeCompanie;
	this->origine = z.origine;
	this->destinatie = z.destinatie;
	this->distanta = z.distanta;
	this->durata = z.durata;
	this->time.ora = z.time.ora;
	this->time.minut = z.time.minut;
	this->pretMin = z.pretMin;
	this->pretMax = z.pretMax;

}

Zbor& Zbor::operator=(const Zbor& z)
{
	if (this != &z)
	{
		this->nrZbor = z.nrZbor;
		this->numeCompanie = z.numeCompanie;
		this->origine = z.origine;
		this->destinatie = z.destinatie;
		this->distanta = z.distanta;
		this->durata = z.durata;
		this->time.ora = z.time.ora;
		this->time.minut = z.time.minut;
		this->pretMin = z.pretMin;
		this->pretMax = z.pretMax;
	}
	return* this;
}

void Zbor::afisare()
{
	cout << "NUMARUL ZBORULUI: " << '\t' << '\t' << this->nrZbor << '\n';
	cout << "NUMELE COMPANIEI: " << '\t' << '\t' << this->numeCompanie << '\n';
	cout << "ORIGINE: " << '\t' << '\t' << '\t' << this->origine << '\n';
	cout << "DESTINATIE: " << '\t' << '\t' << '\t' << this->destinatie << '\n';
	cout << "DISTANTA: " << '\t' << '\t' << '\t' << this->distanta << '\t' << " miles" << '\n';
	cout << "DURATA: " << '\t' << '\t' << '\t' << this->durata << '\t' << " min" << '\n';
	cout << "TIMPUL DE PLECARE: " << '\t' << '\t' << this->time.ora << ":" << this->time.minut << '\n';
	cout << "PRETUL MINIM PER BILET: " << '\t' << this->pretMin << '\t' << " $" << '\n';
	cout << "PRETUL MAXIM PER BILET: " << '\t' << this->pretMax << '\t' << " $" << '\n';
}

bool Zbor::operator!=(const Zbor& z)
{
	return this->nrZbor==z.nrZbor && this->numeCompanie==z.numeCompanie && this->origine==z.origine && this->destinatie==z.destinatie && this->distanta==z.distanta && this->durata==z.durata && this->time.ora==z.time.ora && this->time.minut==z.time.minut && this->pretMin==z.pretMin && this->pretMax==z.pretMax;
}



void antet_fisier_scriere(ofstream& f)
{

	f << "NR.ZBOR" << t << t << "NUME COMPANIE" << t << t << t << "ORIGINE" << t << t << t << t << "DESTINATIE" << t << t << t << "DISTANTA" << t << t << "DURATA" << t << t << "TIME" << t << t << "PRET MIN (USD)" << t << "PRET MAX (USD)" << n;
	for (int i = 1; i <= 174; i++)
		f << "-";
	f << n << n;
	//3 15
}

istream& operator>>(istream& input, Zbor& z)
{
	cout << "NUMARUL ZBORULUI: ";
	input >> z.nrZbor;
	cout << "NUMELE COMPANIEI: ";
	input >> z.numeCompanie;
	cout << "ORIGINE: ";
	input >> z.origine;
	cout<<"DESTINATIE: ";
	input >> z.destinatie;
	cout << "DISTANTA: ";
	input >> z.distanta;
	cout << "DURATA: ";
	input >> z.durata;
	cout << "TIMPUL DE PLECARE: ";
	cout << '\n' << '\t' << "ORA: ";
	input >> z.time.ora;
	cout << "\t" << "MINUT: ";
	input >> z.time.minut;
	cout << "PRET MINIM PER BILET: ";
	input >> z.pretMin;
	cout << "PRET MAXIM PER BILET: ";
	input >> z.pretMax;

	return input;

	// // O: insert return statement here
}

ostream& operator<<(ostream& consola, const Zbor& z)
{
	consola << "NUMARUL ZBORULUI: " << '\t' << '\t' << z.nrZbor << '\n';
	consola << "NUMELE COMPANIEI: " << '\t' << '\t' << z.numeCompanie << '\n';
	consola << "ORIGINE: " << '\t' << '\t' << '\t' << z.origine << '\n';
	consola << "DESTINATIE: " << '\t' << '\t' << '\t' << z.destinatie << '\n';
	consola << "DISTANTA: " << '\t' << '\t' << '\t' << z.distanta << '\t' << " miles" << '\n';
	consola << "DURATA: " << '\t' << '\t' << '\t' << z.durata << '\t' << " min" << '\n';
	consola << "TIMPUL DE PLECARE: " << '\t' << '\t' << z.time.ora << ":" << z.time.minut << '\n';
	consola << "PRETUL MINIM PER BILET: " << '\t' << z.pretMin << '\t' << " $" << '\n';
	consola << "PRETUL MAXIM PER BILET: " << '\t' << z.pretMax << '\t' << " $" << '\n';

	return consola;
	// // O: insert return statement here
}

//ofstream 1
ofstream& operator<<(ofstream& f, const Zbor& z)
{
	string aux;
	//int nr;
	//f << z.nrZbor  << t << t;
	if (z.nrZbor.length() <= 5)
	{
		//f << "   ";
		aux = z.nrZbor;
		aux = z.nrZbor + "   ";
		f << aux << t << t;

	}
	else f << z.nrZbor << t << t;

	//aux = z.numeCompanie;
	//for (int i = z.numeCompanie.length(); i <= 17; i++)
	//	aux = aux + " ";
	////f << aux << t << t << t << t;
	//f << aux;


	if (z.numeCompanie.length() <= 5) 
	{
		//f << "   ";
		aux = z.numeCompanie;
		aux = aux + " ";
		f << aux << t << t << t << t;

	}
	else f << z.numeCompanie << t << t << t << t;

		//aux = z.origine;
		//for (int i = z.origine.length(); i <= 23; i++)
		//	aux = aux + " ";
		////f << aux << t << t << t << t;
		//f << aux;

	if (z.origine.length() <= 5)
	{
		//f << "   ";
		aux = z.origine;
		aux = (string)z.origine + "   ";
		f << aux << t << t << t;

	}
	else if (z.origine.length() >= 8)
		f << z.origine << t << t;
	else f << z.origine << t << t << t;

		//aux = z.destinatie;
		//for (int i = z.destinatie.length(); i <= 23; i++)
		//	aux = aux + " ";
		////f << aux << t << t << t << t;
		//f << aux;
	if (z.destinatie.length() <= 5) {
		//f << "   ";
		aux = z.destinatie;
		aux = (string)z.destinatie + "   ";
		f << aux << t << t << t;
	}
	else if (z.destinatie.length() >= 8)
		f << z.destinatie << t << t;
	else f << z.destinatie << t << t << t;

	f << z.distanta << t << t << t << z.durata << t << t << t << z.time.ora << ":" << z.time.minut << t << t << z.pretMin << t << t << t << z.pretMax << n;


	//f << z.nrZbor << t << t << z.numeCompanie;
	//if (z.numeCompanie.length() <= 5) {
	//	f << "   ";
	//	/*string aux;
	//	aux = z.numeCompanie;
	//	aux = (string)z.numeCompanie + "   ";*/
	//}
	//f << t << t << t << t << z.origine;
	//if (z.origine.length() <= 5) {
	//	f << "   ";
	//}
	//f << t << t << t << z.destinatie;
	//if (z.destinatie.length() <= 5) {
	//	f << "   ";
	//}

	//f << t << t << t << z.distanta << t << t << t << z.durata << t << t << t << z.time.ora << ":" << z.time.minut << t << t << z.pretMin << t << t << t << z.pretMax << n;

	return f;


}



//ofstream& operator<<(ofstream& f, const Zbor& z)
//{
//	f << z.nrZbor;
//	//18
//	f.width(18);
//	f << z.numeCompanie;
//	f.width(30);
//	f << z.origine;
//	f.width(24);
//	f << z.destinatie;
//	f.width(25);
//	//f<<
//	return f;
//	// // O: insert return statement here
//}

ifstream& operator>>(ifstream& g, Zbor& z)
{
	
	g >> z.nrZbor >> z.numeCompanie >> z.origine >> z.destinatie >> z.distanta >> z.durata >> z.time.ora;
	g.ignore();
	g >> z.time.minut >> z.pretMin >> z.pretMax;
	return g;
	// // O: insert return statement here
}

int operator+(const Zbor& z1, const Zbor& z2)
{
	
	int aux ;
	aux = z1.durata + z2.durata;

	return aux;
	
}





int Zbor::validare(Zbor z,string origine, string destinatie)
{
	if (origine == z.origine && destinatie == z.destinatie) return 1;
	return 0;
}

string Zbor::getnrZbor()
{
	return this->nrZbor;
}

string Zbor::getNumeCompanie()
{
	return this->numeCompanie;
}

string Zbor::getOrigine()
{
	return this->origine;
}

string Zbor::getDestinatie()
{
	return this->destinatie;
}

float Zbor::getDistanta()
{
	return this->distanta;
}

int Zbor::getDurata()
{
	return this->durata;
}

int Zbor::getTimeOra()
{
	return this->time.ora;
}

int Zbor::getTimeMin()
{
	return this->time.minut;
}

float Zbor::getPretMin()
{
	return this->pretMin;
}

float Zbor::getPretMax()
{
	return this->pretMax;
}

void Zbor::setNrZbor(string nrZbor)
{
	if (nrZbor != "" && nrZbor != this->nrZbor && nrZbor.length()>=6)
	{
		this->nrZbor = nrZbor;
	}
	else throw "ERROR: NUMAR ZBOR INVALID";
}

void Zbor::setNumeCompanie(string numeCompanie)
{
	if (numeCompanie != "" && numeCompanie!=this->numeCompanie)
	{
		this->numeCompanie = numeCompanie;
	}
	else throw "ERROR: NUME COMPANIE INVALID!";
}

void Zbor::setOrigine(string origine)
{
	if (origine != "" && origine!=this->origine)
	{
		this->origine = origine;
	}
	else throw "ERROR: ORIGINE INVALIDA!";
}

void Zbor::setDestinatie(string destinatie)
{
	if (destinatie != "" && destinatie!=this->destinatie)
	{
		this->destinatie = destinatie;
	}
	else throw "ERROR: DESTINATIE INVALIDA!";
}

void Zbor::setDistanta(float distanta)
{
	if (distanta > 0 && this->distanta!=distanta)
	{
		this->distanta = distanta;
	}
	else throw "ERROR: DISTANTA INVALIDA!";
}

void Zbor::setDurata(int durata)
{
	if (durata > 0 && durata!=this->durata)
	{
		this->durata = durata;
	}
	else throw "ERROR: DURATA INVALIDA!";
}

void Zbor::setPretMin(float pretMin)
{
	if (pretMin <= 0 && pretMin < this->pretMax && pretMin != this->pretMin)
	{
		this->pretMin = pretMin;
	}
	else throw "ERROR: VALOARE PRET MINIM INVALIDA!";

}

void Zbor::setPretMax(float pretMax)
{
	if (pretMax > 0 && pretMax > this->pretMin && pretMax != this->pretMax)
	{
		this->pretMax = pretMax;
	}
	else throw"ERROR: VALOAREA PRET MAXIM INVAIDA!";
}
