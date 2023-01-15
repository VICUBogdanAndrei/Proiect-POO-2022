#define _CRT_SECURE_NO_WARNINGS
#define n '\n'

#include "Bilet.h"
#include <string>
#include <fstream>

//string afisareClasa(clasa ales)
//{
//	if (ales == Economy)
//		return "Economy";
//	else if (ales == Business)
//		return "Business";
//	else if (ales == First)
//		return "First";
//	else return "-1";
//}

//istream& operator>>(istream& input, clasa& tip)
//{
//	cout << "TIPUL CLASEI: ";
//	input >> tip;
//	return input;
//	// // O: insert return statement here
//}
//
//ostream& operator<<(ostream& consola, const clasa& tip)
//{
//	consola << tip<<'\n';
//	return consola;
//	// // O: insert return statement here
//}

istream& operator>>(istream& input, Bilet& b)
{
	cout << "LOCUL DORIT (format: A12): ";
	input >> b.loc;
	cout << "BAGAJ DE CALA: (DA - 1 , NU - 0): ";
	input >> b.bagajCala;
	cout << "TIPUL CLASEI: ";
	char buffer[100];
	input.ignore();
	input >> buffer;
	b.tip = new char[strlen(buffer) + 1];
	strcpy(b.tip, buffer);
	cout << "NUMAR ZBOR:";
	input >> b.nr_zbor;
	input.ignore();
	return input;
	// // O: insert return statement here
}

ostream& operator<<(ostream& consola, const Bilet& b)
{
	consola << "LOCUL DORIT: " << '\t' << '\t' << '\t' << b.loc << '\n';
	consola << "BAGAJ DE CALA: ";
	if (b.bagajCala == 0) consola << '\t' << '\t' << '\t' << "NU" << '\n';
	else consola << '\t' << '\t' << '\t' << "DA" << '\n';
	consola << "TIPUL CLASEI: " << '\t' << '\t' << '\t';
	if (b.tip == NULL) consola << " " << '\n';
	else consola << b.tip << '\n';
	consola << "NUMARUL ZBORULUI: " << t << t <<b.nr_zbor << n;
	return consola;
	// // O: insert return statement here
}

ofstream& operator<<(ofstream& output, const Bilet& b)
{
	//output << "LOCUL DORIT  BAGAJ DE CALA(0/1)  CLASA  NUMAR ZBOR";
	output << b.loc << " " << b.bagajCala << " " << b.tip << " " << b.nr_zbor << n;
	return output;
	// // O: insert return statement here
}

ifstream& operator>>(ifstream& inputfile, Bilet& b)
{
	inputfile >> b.loc;
	inputfile >> b.bagajCala;
	char buffer[100];
	inputfile >> buffer;
	b.tip = new char[strlen(buffer) + 1];
	strcpy(b.tip, buffer);
	inputfile>> b.nr_zbor;

	return inputfile;
	// // O: insert return statement here
}

bool operator==(const Bilet& b1, const Bilet& b2)
{
	if (b1.loc == b2.loc) return 1;
	return 0;
}

int Bilet::contor = 9000;

Bilet::Bilet() :id_bilet(contor++)
{
	this->loc = "";
	this->bagajCala = 0;
	this->tip = NULL;
	this->nr_zbor = "";
}

Bilet::Bilet(string loc, bool bagajCala, char* tip, string nr_zbor): id_bilet(contor++)
{
	this->loc = loc;
	this->bagajCala = bagajCala;
	this->tip = new char[strlen(tip) + 1];
	strcpy(this->tip, tip);
	this->nr_zbor = nr_zbor;
}

Bilet::Bilet(const Bilet& b): id_bilet(contor++)
{
	this->loc = b.loc;
	this->bagajCala = b.bagajCala;
	this->tip = new char[strlen(b.tip) + 1];
	strcpy(this->tip, b.tip);
	this->nr_zbor = b.nr_zbor;
}

Bilet& Bilet::operator=(const Bilet& b)
{
	if (this != &b)
	{
		this->loc = b.loc;
		this->bagajCala = b.bagajCala;
		if (this->tip != NULL) delete[] this -> tip;
		this->tip = new char[strlen(b.tip) + 1];
		strcpy(this->tip, b.tip);
		this->nr_zbor = b.nr_zbor;
	}

	return *this;
	// // O: insert return statement here
}

bool Bilet::operator!=(const Bilet& b)
{
	if (this->loc!=b.loc) return 1;
	return 0;
}

string Bilet::getLoc()
{
	return this->loc;
}

bool Bilet::getBagajCala()
{
	return this->bagajCala;
}

char* Bilet::getTip()
{
	return this->tip;
}

string Bilet::getNrZbor()
{
	return this->nr_zbor;
}

void Bilet::setLoc(string loc)
{
	if (loc != "" && loc != this->loc)
	{
		this->loc = loc;
	}
	else throw "ERROR: LOC INVALID!";
}

void Bilet::setBagajCala(bool bagajCala)
{
	if (bagajCala != this->bagajCala)
		this->bagajCala = bagajCala;
	else throw "ERROR: BAGAJ CALA INVALID!";
}

void Bilet::setTip(char* tip)
{
	if (tip != NULL && tip != this->tip )
	{
		delete[] this->tip;
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
	}
	else throw "ERROR: TIPUL BILETULUI INVALID! VALID DOAR: Economy, First, Business";
}

void Bilet::setNrZbor(string nr_zbor)
{
	if (nr_zbor != "" && nr_zbor != this->nr_zbor)
		this->nr_zbor = nr_zbor;
	else throw "ERROR: NUMARUL ZBORULUI ESTE INVALID!";
}

Bilet::~Bilet()
{
	if (this -> tip != NULL)
	{
		delete[] this->tip;
		this->tip = NULL;
	}
}



