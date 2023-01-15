#define _CRT_SECURE_NO_WARNINGS
#define n '\n'


#include "Zbor.h"
#include "Avion.h"
#include "Bilet.h"
#include "Pasager.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


using  namespace std;

//ifstream in("ZBOR.txt");
//ofstream out("ZBOR.txt");

//void creare_fisier()
//{
//	FILE* f;
//	f = NULL;
//	f = fopen("ZBOR.txt", "w");
//	if (!f)
//		cout << "FISIERUL NU S-A DESCHIS";
//	else {
//		fprintf(f, "ID \t NUME COMPANIE \t ORIGINE \t  DESTINATIE \t  DISTANTA \t DURATA \t TIME \t PRET MINIM \t PRET MAXIM \t");
//	}
//	fclose(f);
//}

int main()
{
	//cout << "Hello World!";
	//cout << "EU SUNT BOGDAN";
	//cout << '\n';

	//Zbor z1;

	////z1.afisare();

	//Zbor z2("WZ1234","WIZZAIR", "BUCURESTI", "PARIS", 2000, 180, 20, 30, 20, 300);

	//cout << '\n' << '\n';
	//cout << z2;

	//Zbor z3 = z2;
	//cout << '\n' << '\n';
	//cout << '\n' << '\n';
	//int durata = z2 + z3;
	//cout << "DURATA TOTALA: " << durata;
	//cout << '\n' << '\n';
	//cout << '\n' << '\n';





	//z3.afisare();

	///*Zbor z4("TAROM", "CLuj Napoca", "Bucuresti", 700, 45, 13, 30, 50, 150);
	//Zbor z5;
	//z5 = z4;*/

	//cout << '\n' << '\n';
	//cout << '\n' << '\n';

	////z5.afisare();

	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';

	////Zbor z6;
	////cin >> z6;

	//cout << '\n';
	//cout << '\n';
	////cout << z6;

	////creare_fisier();
	////z6.scriere_fisier();

	////out << z4;

	//cout << '\n' << '\n';
	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';

	////char* s=new string[8];
	//char* cuv = new char[strlen("AIR300") + 1];
	//strcpy(cuv, "AIR300");
	//Avion a1(cuv, 300,8,30000,z2);
	////a1.afisare();

	//Avion a2;
	////a2.afisare();
	//string s = "AIR300";
	//Avion a3("AIR23", 20, 4, 3000, z2);

	//cout << a3;
	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';
	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';
	//Avion a4 = a3;
	//cout << a4;

	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';

	//Avion a5("AIR300", 300, 8, 30000, z2);
	//cout << a5;
	//cout << '\n' << '\n';
	//Avion a6;
	//a6 = a5;
	//cout << a6;

	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	///*Avion a7;
	//cin >> a7;*/
	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	////cout << a7;


	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';
	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';
	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';
	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';

	//////clasa BILET

	//char* cuv1 = new char[strlen("First") + 1];
	//strcpy(cuv1, "First");
	//Bilet b1("K34", 1, cuv1, a5);
	//cout << b1;
	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';

	//char* cuv2 = new char[strlen("Economy") + 1];
	//strcpy(cuv2, "Economy");
	//Bilet b2("K34", 0, cuv2, a3);
	//cout << b2;
	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';

	//if (b1 != b2)
	//	cout << "LOCURILE SUNT DIFERITE!";
	//else
	//	cout << "NU POT STA PE ACElASI LOC DOUA PERSOANE!";
	//
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';

	//if (b1 == b2)
	//	cout << "NU POT STA PE ACElASI LOC DOUA PERSOANE!";
	//else
	//	cout << "LOCURILE SUNT DIFERITE!";


	////cout << "BILET B7" << '\n' << '\n';
	////Bilet b7;
	////cout << b7;

	//////Bilet b3 = b2;
	//////cout << b3;

	//cout << '\n' << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n';
	//cout << "-----------------------------------------------------------------";
	//cout << '\n' << '\n';

	////Bilet b4;
	////b4 = b2;
	////cout << b4;

	////cout << '\n' << '\n';
	////cout << "-----------------------------------------------------------------";
	////cout << '\n';
	////cout << "-----------------------------------------------------------------";
	////cout << '\n' << '\n';
	////cout << '\n' << '\n';
	////cout << "-----------------------------------------------------------------";
	////cout << '\n';
	////cout << "-----------------------------------------------------------------";
	////cout << '\n' << '\n';

	////Bilet b5;
	////cin >> b5;
	////cout << '\n';
	////cout << "------------------AFISARE----------------------------------------";
	////cout << '\n' << '\n';
	////cout << b5;

	//cout << n << n << n;
	//cout << "PASAGER CLASS: ";
	//cout << n << n << n;
	//Pasager p1;
	//cout << p1;
	//
	//cout << n << n << n;
	//cout << "PASAGER 2";
	//cout << n;
	//char* s1 = new char[strlen("Popescu") + 1];
	//strcpy(s1, "Popescu");
	//char* s2 = new char[strlen("Alexandru") + 1];
	//strcpy(s2, "Alexandru");
	//Pasager p2(s1, s2, 5020502270026, 2, "NT", "061932");
	////Pasager p2("Popescu", "Alexandru", 5020502270026, 2, "NZ", "061932");
	//cout << p2;

	//cout << n << n << n;
	//cout << "PASAGER 3";
	//cout << n;
	//Pasager p3 = p2;
	//cout << p3;

	//cout << n << n << n;
	//cout << "PASAGER 4";
	//cout << n;
	//Pasager p4;
	//p4 = p2;
	//cout << p4;

	//cout << n << n << n;
	//cout << "PASAGER 5"<< n;
	//Pasager p5;
	//cin >> p5;
	//cout << n << n;
	//cout << p5;

	//cout << n << n << n;
	//cout << "PASAGER 6" << n;
	//Pasager p6;
	//cin >> p6;
	//cout << n << n;
	//cout << p6;

	//ofstream dateZbor;
	//dateZbor.open("Zbor.txt", ios::out|ios::app);
	//if (!dateZbor)
	//{
	//	cout << "FISIERUL NU A PUTUT FI CREAT"<<n;

	//}
	//else {
	//	//Zbor* z;
	//	int nr = 1;
	//	//z = new Zbor[sizeof(z)];
	//	cout << "FISIER CREAT CU SUCCES!"<<n;
	//	dateZbor << n;
	//	antet_fisier_scriere(dateZbor);
	//	for (int i = 0; i < nr; i++)
	//	{
	//		Zbor z;
	//		cin >> z;
	//		dateZbor << z;
	//		cout << n << n;
	//		
	//	}
	//	dateZbor.close();
	//}

	//citire date din fisier txt


	//}

	//PASAGER
	Pasager p1;
	//cin >> p1;
	//cout << n << n << p1;


	/*ofstream dateout;
	dateout.open("pasager.txt", ios::out | ios::app);
	if (!dateout)
		{
			cout << "FISIERUL NU A PUTUT FI GASIT"<<n;

		}
		else {
			cout << "FISIER CREAT CU SUCCES!"<<n;
			dateout << n;
			dateout << p1;
			dateout.close();
		}*/
	
	
	/*ifstream datein;
	datein.open("pasager.txt", ios::in);
		if (!datein)
	{
		cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
	}
	else {
			
			string dummyline;
			getline(datein, dummyline);
			Pasager p;
			while (!datein.eof())
			{
				datein >> p;
				cout << p << n;
			}
		}*/

	return 0;
}
