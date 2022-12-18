#pragma once
#define n '\n'
#define t '\t'
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

void antet_fisier_scriere(ofstream&);


class Zbor
{
private:
	string nrZbor;
	string numeCompanie;
	string origine;
	string destinatie;
	float distanta; //miles
	int durata; //minute
	struct {
		int ora;
		int minut;
	}time;
	float pretMin; //$
	float pretMax; //$

	static int contor;

public:

	//constructor fara parametrii - DONE
	Zbor();

	//constructor cu parametrii - DONE
	Zbor(string, string, string, string, float, int, int, int, float, float);

	//constructor de copiere - DONE

	Zbor(const Zbor&);

	//operatorul = - DONE

	Zbor& operator=(const Zbor&);

	//metoda afisare - DONE
	void afisare();


	//istream cin>>
	friend istream& operator>> (istream&, Zbor&);

	//ostream
	friend ostream& operator<< (ostream&, const Zbor&);
	
	//ofstream - supraincvaracre operator de scriere in fisier
	// 
	friend ofstream& operator<<(ofstream&, const Zbor&);
	//friend ofstream& operator<<(ofstream&, const Zbor&);

	//ifstream - supraincarcare opeartor de citire din fisier
	friend ifstream& operator>> (ifstream&, Zbor&);

	//operator!=
	bool operator!=(const Zbor&);


	//operator +
	//duarata a doua zboruri
	//ex zborurui cu escala
	friend int operator+(const Zbor&,const Zbor&);



	//int nrZbor;
	string getnrZbor();

	string getNumeCompanie();

	string getOrigine();

	string getDestinatie();

	float getDistanta(); //miles

	int getDurata(); //minute

	int getTimeOra();

	int getTimeMin();

	float getPretMin(); //$

	float getPretMax(); //$

	//setteri

	void setNrZbor(string);

	void setNumeCompanie(string);

	void setOrigine(string);

	void setDestinatie(string);

	void setDistanta(float); //miles

	void setDurata(int); //minute

	void setPretMin(float); //$

	void setPretMax(float); //$


};

