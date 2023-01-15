#pragma once
#define n '\n'
#include <iostream>
#include <fstream>
#include <string>
#include "Avion.h"
#include "Zbor.h"

using namespace std;

//enum clasa {
//	Economy, 
//	Business,
//	First
//};
//
//string afisareClasa(clasa);



//istream& operator>> (istream&, clasa&);
//
//ostream& operator<< (ostream&, const clasa&);


class Bilet
{
private:
	const int id_bilet;
	static int contor;
	string loc; //max 3 caractere
	bool bagajCala;
	char* tip;
	string nr_zbor;

public:

	//constructor fara parametrii 

	Bilet();

	//constructor cu parametrii

	Bilet(string, bool, char*, string);

	//constructor de copiere

	Bilet(const Bilet&);

	//operator =

	Bilet& operator=(const Bilet&);


	//istream 
	
	friend istream& operator>> (istream&, Bilet& );


	//ostream

	friend ostream& operator<< (ostream&, const Bilet& );

	//ofstream
	friend ofstream& operator<< (ofstream&, const Bilet&);

	//ifstream
	friend ifstream& operator>> (ifstream& inputfile, Bilet& b);

	//operator!=
	//verificare daca locul este ocupat sau nu 
	bool operator!= (const Bilet&);
	
	friend bool operator==(const Bilet&, const Bilet&);
	
	
	
	
	//getteri 
	string getLoc(); //max 3 caractere
	
	bool getBagajCala();
	
	char* getTip();

	string getNrZbor();

	//setteri

	void setLoc(string); //max 3 caractere
	void setBagajCala (bool);
	void setTip(char*);
	void setNrZbor(string);

	//destructor

	~Bilet();


};

