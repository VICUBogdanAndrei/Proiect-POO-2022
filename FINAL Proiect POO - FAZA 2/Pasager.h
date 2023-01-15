#pragma once
#define n '\n'
#define t '\t'
#include <string>
#include "Bilet.h"


using namespace std;

enum document {
	CI,
	PE,
	CN //certificat nastere

};

class Pasager
{
private:
	char* nume;
	char* prenume;
	long long CNP;
	int nrBagaje;
	//float* greutateBagaje;
	string seria;
	string numar;
	string nr_zbor;
	//Bilet b;

public:
	//constructor fara parametrii 

	Pasager();

	//constructor cu parametrii

	Pasager(char*, char*, long long, int, string, string, string);

	//Pasager(string, string, long long, int, string, string);

	//constructor de copiere

	Pasager (const Pasager&);


	//operator =

	Pasager& operator= (const Pasager&);

	//istream 

	friend istream& operator>> (istream&, Pasager&);

	//ostream

	friend ostream& operator<< (ostream&, const Pasager&);

	//oftsream

	friend ofstream& operator<< (ofstream& outputfile, const Pasager& p);


	//ifstream

	friend ifstream& operator>>(ifstream& inputfile, Pasager& p);

	//metoda statica
	//varsta pasagerului
	static int varstaPasager(const Pasager&);


	//getteri 

	char* getNume();
	char* getPrenume();
	long long getCNP();
	int getNrBagaje();
	//float* greutateBagaje;
	string getSeria();
	string getNumar();
	string getNrZbor();

	//setteri

	void setNume(char*);
	void setPrenume(char*);
	void setCNP(long long);
	void setNrBagaje (int);
	//float* greutateBagaje;
	void setSeria (string);
	void setNumar(string);
	void setNrZbor(string);


	//destructor

	~Pasager();







};

