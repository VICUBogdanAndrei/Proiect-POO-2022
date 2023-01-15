#define _CRT_SECURE_NO_WARNINGS
#define n '\n'

#include "Bilet.h"
#include <string>

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
	input >> b.a;
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
	consola << b.a;
	return consola;
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
}

Bilet::Bilet(string loc, bool bagajCala, char* tip, Avion a): id_bilet(contor++)
{
	this->loc = loc;
	this->bagajCala = bagajCala;
	this->tip = new char[strlen(tip) + 1];
	strcpy(this->tip, tip);
	this->a = a;
}

Bilet::Bilet(const Bilet& b): id_bilet(contor++)
{
	this->loc = b.loc;
	this->bagajCala = b.bagajCala;
	this->tip = new char[strlen(b.tip) + 1];
	strcpy(this->tip, b.tip);
	this->a = b.a;
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
		this->a = b.a;
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
	if (tip != NULL && tip != this->tip && (tip == "Economy" || tip == "First" || tip == "Business"))
	{
		delete[] this->tip;
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
	}
	else throw "ERROR: TIPUL BILETULUI INVALID! VALID DOAR: Economy, First, Business";
}

Bilet::~Bilet()
{
	if (this -> tip != NULL)
	{
		delete[] this->tip;
		this->tip = NULL;
	}
}



