#define _CRT_SECURE_NO_WARNINGS
#define n '\n'
#define t '\t'
//#define readline(file,dummy) getline(file,dummy)

#include "Zbor.h"
#include "Avion.h"
#include "Bilet.h"
//#include "Meniu.cpp"
#include "Pasager.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using  namespace std;

void meniu()
{
	cout << n << n;
	cout << "-------------------------------------------------------" << n;
	cout << "------------ TICKETING APP - FLIGHT TICKET ------------" << n;
	cout << "-------------------------------------------------------" << n;
	cout << "--------------------->>> MENIU <<<---------------------" << n;
	cout << "-------------------------------------------------------" << n;
	cout << "-------- 1. AFISARE ZBORURI DISPONIBILE ---------------" << n;
	cout << "-------- 2. VERIFICARE REZERVARE ----------------------" << n;
	cout << "-------- 3. CREARE O NOUA REZERVARE -------------------" << n;
	cout << "-------- 4. VERIFICARE DISPONIBILITATE LOCURI ---------" << n;
	cout << "-------- 5. VERIFICARE EXISTENTA ZBOR DORIT -----------" << n;
	cout << "-------- 6. AFISARE ITINERARIU ------------------------" << n;
	cout << "-------- 7. EXIT --------------------------------------" << n;
	cout << "-------------------------------------------------------" << n;
	cout << n;
	cout << n;
	cout << "INTRODUCETI NUMARUL DIN MENIU CORESPUNZATOR CERINTEI: ";
	//cout << n;
}

void meniu_1()
{
	ifstream datein;
	datein.open("Zbor.txt", ios::in);
	if (!datein)
	{
		cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
	}
	else {
		Zbor z;
		string dummyline;
		getline(datein, dummyline);
		while (!datein.eof())
		{
			datein >> z;
			cout << z;
			cout << n << n;
		}
		datein.close();
	}
}

void meniu_2()
{
	char nume[100];
	cout << "INTRODUCETI NUMELE PASAGERULUI: ";
	cin >> nume;

	char prenume[100];
	cout << "INTRODUCETI PRENUMELE PASAGERULUI: ";
	cin >> prenume;

	//cout << nume;

	Pasager p;
	Bilet b;
	int ok = 0;

	//fisier pasager
	ifstream datein;
	datein.open("Pasager.txt", ios::in);
	if (!datein)
	{
		cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
	}
	else
	{
		string dummyline;
		getline(datein, dummyline);
		int ok = 0;
		while (!datein.eof() && ok==0)
		{
			datein >> p;
			if (strcmp(p.getNume(), nume)==0  && strcmp(p.getPrenume(), prenume) == 0) ok = 1;
		}
		datein.close();

		if (ok==0) cout << n<< "ERROR: PASAGER NEIDENTIFICAT";
		else 
		{
			cout << n << n;
			cout << p;

			//fisier bilet
			cout << n << n;
			//	cout << p;
			ifstream dateinp;
			dateinp.open("Bilet.txt", ios::in);
			if (!dateinp)
			{
				cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
			}
			else
			{
				string dummyline;
				getline(dateinp, dummyline);
				int okb=0;
				while (!dateinp.eof() && okb == 0)
				{
					dateinp >> b;
					if (p.getNrZbor() == b.getNrZbor()) okb = 1;
				}
				dateinp.close();

				if (okb == 0) cout << "BILET NEGASIT!";
				else cout << b;

			}
			

		}
	}

}

void meniu_3()
{
	cout << "INTRODUCETI ORIGINEA ZBORULUI DORIT: ";
	string origine;
	cin >> origine;
	cout << "INTRODUCETI DESTINATIA ZBORULUI DORIT: ";
	string destinatie;
	cin >> destinatie;
	//cout << origine << n << destinatie;

	Zbor z;
	Pasager p;
	Bilet b;
	//int ok = 0;
	ifstream datein;
	datein.open("Zbor.txt", ios::in);
	if (!datein)
	{
		cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
	}
	else
	{
		string dummyline;
		getline(datein, dummyline);

		int ok = 0;
		while (!datein.eof() && ok==0)
		{
			datein >> z;
			ok= z.validare(z, origine, destinatie);
			/*
			if (z.getOrigine() == origine && z.getDestinatie() == destinatie) ok = 1;
			*/
		}

		datein.close();

		if (ok == 0) cout << "ZBOR INEXISTENT!";
		else {
			cin.ignore();
			cin >> p;

			p.setNrZbor(z.getnrZbor());

			//biletul
			
			Bilet ub; //ukltim bilet din fisier
			ifstream dateinb;
			dateinb.open("bilet.txt", ios::in);
			if (!dateinb)
			{
				cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";

			}
			else
			{
				string dummyline;
				getline(dateinb, dummyline);
				while (!dateinb.eof())
				{
					dateinb >> ub;
				}
				dateinb.close();

			}

			string loc = ub.getLoc();
			loc[2] = loc[2] + 1;
			b.setLoc(loc);

			if (p.getNrBagaje() > 1)
			{
				bool bc; //bagaj cala
				cout << "DORITI BAGAJ DE CALA? (DA - 1, NU - 0) ";
				cin >> bc;
				b.setBagajCala(bc);
			}
			cout << "TIPUL CLASEI: (Economy, Business, First) ";
			char buffer[100];
			//cin.ignore();
			cin>>buffer;
			char* aux;
			aux = new char[strlen(buffer) + 1];
			strcpy(aux, buffer);
			b.setTip(aux);

			b.setNrZbor(z.getnrZbor());

			cout << "BILET CREAT CU SUCCES!" << n;
		}

	}
	ofstream dateout;
	dateout.open("pasager.txt", ios::out | ios::app);
	if (!dateout)
		{
			cout << "FISIERUL NU A PUTUT FI GASIT"<<n;

		}
		else {
			dateout << n;
			dateout << p;
			dateout.close();
		}
	//ofstream dateout;
	dateout.open("bilet.txt", ios::out | ios::app);
	if (!dateout)
	{
		cout << "FISIERUL NU A PUTUT FI GASIT" << n;

	}
	else {
		dateout << n;
		dateout << b;
		dateout.close();
	}

}

void meniu_4()
{
	Pasager p;
	Avion a;
	char nume[100];
	cout << "INTRODUCETI NUMELE PASAGERULUI: ";
	cin >> nume;

	char prenume[100];
	cout << "INTRODUCETI PRENUMELE PASAGERULUI: ";
	cin >> prenume;

	//cout << nume << prenume;

	ifstream datein;
	datein.open("Pasager.txt", ios::in);
	if (!datein)
	{
		cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
	}
	else
	{
		string dummyline;
		getline(datein, dummyline);
		int ok = 0;
		while (!datein.eof() && ok == 0)
		{
			datein >> p;
			if (strcmp(p.getNume(), nume) == 0 && strcmp(p.getPrenume(), prenume) == 0) ok = 1;
		}
		datein.close();

		if (ok == 0) cout << n << "ERROR: PASAGER NEIDENTIFICAT";
		else
		{
			cout << n << n;
			cout << p;
			int ok = 0;
			datein.open("Avion.txt", ios::in);
			if (!datein)
			{
				cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
			}
			else
			{
				string dummyline;
				getline(datein, dummyline);
				while (!datein.eof() && ok == 0)
				{
					datein >> a;
					if (a.getNrZbor() == p.getNrZbor()) ok = 1;
				}
				datein.close();
			}
			if (ok == 0)  cout << "AVIONUL ACESTUI PASAGER NU A FOST GASIT!";
			else
			{
				Bilet b;
				Zbor z;
				cout << n;
				//cout << a;

				int loc_oc = 0;
				ifstream dateinb;
				dateinb.open("bilet.txt", ios::in);
				if (!dateinb)
				{
					cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
				}
				else
				{
					int nr = 0;
					string dummyline;
					getline(dateinb, dummyline);
					while (!dateinb.eof())
					{
						dateinb >> b;
						if (b.getNrZbor() == p.getNrZbor()) loc_oc++;
					}
					dateinb.close();
					//loc_oc = nr;
				}

				ifstream dateinz;
				dateinz.open("Zbor.txt", ios::in);
				if (!dateinz)
				{
					cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
				}
				else
				{
					int ok = 0;
					string dummyline;
					getline(dateinz, dummyline);
					while (!dateinz.eof() && ok == 0)
					{
						dateinz >> z;
						if (z.getnrZbor() == p.getNrZbor()) ok = 1;
					}
					dateinz.close();
				}

				cout << "NUMARUL DE LOCURI OCUPATE DIN AVIONUL CU RUTA " << z.getOrigine() << " - " << z.getDestinatie() << " ESTE DE " << loc_oc << "!" << n;
				cout << "NUMARUL DE LOCURI RAMASE ESTE DE " << a.getNrPasageri() - loc_oc << n;

			}
		}

	}
	


}

void meniu_5()
{
	cout << "INTRODUCETI ORIGINEA ZBORULUI DORIT: ";
	string origine;
	cin >> origine;
	cout << "INTRODUCETI DESTINATIA ZBORULUI DORIT: ";
	string destinatie;
	cin >> destinatie;
	//cout << origine << " - " << destinatie;
	
	Zbor z;
	
	int ok = 0;
	ifstream datein;
	datein.open("Zbor.txt", ios::in);
	if (!datein)
	{
		cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
	}
	else
	{
		;
		string dummyline;
		getline(datein, dummyline);
		while (!datein.eof() && ok == 0)
		{
			datein >> z;
			ok = z.validare(z, origine, destinatie);
		}
		datein.close();
	}
	
	if (ok == 0) 
	{
		cout << "RUTA DORITA NU A FOST GASITA!"<<n;
		ofstream datecereri;
		datecereri.open("cereri.txt", ios::out | ios::app);
		if (!datecereri)
		{
			cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
		}
		else {
			datecereri << origine << "  " << destinatie << n;
		}
		datecereri.close();
		cout << n << "CEREREA DUMNEAVOASTRA A FOST INREGISTRATA!"<<n<<n;
	}
	else {
		cout << "ZBORUL DORIT A FOST GASIT IN BAZA DE DATE, AVAND URMATOARELE INFORMATII: " << n;
		cout << "ORIGINE: " << t << t << t << t << origine<<n;
		cout << "DESTINATIE: " << t << t << t << t << destinatie<<n;
		cout << "DISTANTA: " << t << t << t << t << z.getDistanta()<<t<<" miles"<<n;
		cout << "ORA DE PLECARE: " << t << t << t << z.getTimeOra() << ":" << z.getTimeMin() << n;
		cout << "DURATA CALATORIEI: " << t << t << t << z.getDurata() << t << " minute"<<n;
		cout << "PRET MINIM PER BILET: " << t << t << t << z.getPretMin() << t << " $" << n;
		cout << "PRET MAXIM PER BILET: " << t << t << t << z.getPretMax() << t << " $" << n;

		//locuri disponibile
		Bilet b;
		int loc_oc = 0;
		ifstream dateinb;
		dateinb.open("bilet.txt", ios::in);
		if (!dateinb)
		{
			cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
		}
		else
		{
			int nr = 0;
			string dummyline;
			getline(dateinb, dummyline);
			while (!dateinb.eof())
			{
				dateinb >> b;
				if (b.getNrZbor() == z.getnrZbor()) loc_oc++;
			}
			dateinb.close();
			//loc_oc = nr;
		}

		int ok = 0;
		Avion a;
		ifstream dateina;
		dateina.open("Avion.txt", ios::in);
		if (!dateina)
		{
			cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
		}
		else
		{
			string dummyline;
			getline(dateina, dummyline);
			while (!dateina.eof() && ok == 0)
			{
				dateina >> a;
				if (a.getNrZbor() == z.getnrZbor()) ok = 1;
			}
			datein.close();
		}
		if (ok == 0) {
			cout << "NU SE CUNOASTE NUMARUL DE LOCURI DISPONIBILE!";
		}
		else cout << "NUMARUL LOCURILOR DISPONIBILE: " << t << t<<a.getNrPasageri() - loc_oc << t << " locuri" <<n;

	}

}

//void meniu_7()
//{
//	cout << "DORITI SA AFISATI ITINERARIUL PENTRU TOTI PASAGERII? (0/1)" << n;
//	cout << "RASPUNS: ";
//	int r;
//	cin >> r;
//	
//	Zbor z;
//	if (r == 1)
//	{
//		
//		ifstream datein;
//		datein.open("Pasager.txt", ios::in);
//		if (!datein)
//		{
//			cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
//		}
//		else
//		{
//			string dummyline;
//			getline(datein, dummyline);
//			
//			while (!datein.eof())
//			{
//				Pasager p;
//				datein >> p;
//				cout << "NUMELE PASAGERULUI: " <<t<<t<<t<< p.getNume() << n;
//				cout << "PRENUMELE PASAGERULUI: " << t << t << t << p.getPrenume() << n;
//
//				ifstream dateinz;
//				dateinz.open("Zbor.txt", ios::in);
//				if (!dateinz)
//				{
//					cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
//				}
//				else
//				{
//					int ok = 0;
//					string dummyline;
//					getline(dateinz, dummyline);
//					while (!dateinz.eof() && ok == 0)
//					{
//						dateinz >> z;
//						if (z.getnrZbor() == p.getNrZbor()) ok == 1;
//					}
//
//					if (ok == 0) cout << "ZBORUL NU ESTE ALOCAT PASAGERULUI IN ACEST MOMENT!";
//					else {
//						cout << "ORIGINE: " << t << t << t << t << z.getOrigine() << n;
//						cout << "DESTINATIE: " << t << t << t << t << z.getDestinatie() << n;
//						cout << "DISTANTA: " << t << t << t << t << z.getDistanta() << t << " miles" << n;
//						cout << "ORA DE PLECARE: " << t << t << t << z.getTimeOra() << ":" << z.getTimeMin() << n;
//						cout << "DURATA CALATORIEI: " << t << t << t << z.getDurata() << t << " minute" << n;
//						cout << "NUMELE COMPANIEI: " << t << t << t << z.getNumeCompanie() << n;
//						cout << "NUMARUL ZBORULUI: " << t << t << t << z.getnrZbor() << n;
//						cout << n;
//					}
//
//					dateinz.close();
//				}
//				
//			}
//			datein.close();
//		}
//
//
//	}
//	else
//	{
//		Pasager p;
//		char nume[100];
//		cout << "INTRODUCETI NUMELE PASAGERULUI: ";
//		cin >> nume;
//
//		char prenume[100];
//		cout << "INTRODUCETI PRENUMELE PASAGERULUI: ";
//		cin >> prenume;
//
//		ifstream datein;
//		datein.open("Pasager.txt", ios::in);
//		if (!datein)
//		{
//			cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
//		}
//		else
//		{
//			string dummyline;
//			getline(datein, dummyline);
//			int ok = 0;
//			while (!datein.eof() && ok == 0)
//			{
//				
//				datein >> p;
//				if (strcmp(p.getNume(), nume) == 0 && strcmp(p.getPrenume(), prenume) == 0) ok = 1;
//			}
//
//			cout << "NUMELE PASAGERULUI: " << t << t << t << p.getNume() << n;
//			cout << "PRENUMELE PASAGERULUI: " << t << t << t << p.getPrenume() << n;
//
//			ifstream dateinz;
//			dateinz.open("Zbor.txt", ios::in);
//			if (!dateinz)
//			{
//				cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
//			}
//			else
//			{
//				int okZ = 0;
//				string dummyline;
//				getline(dateinz, dummyline);
//				while (!dateinz.eof() && okZ == 0)
//				{
//					dateinz >> z;
//					//if (z.getnrZbor() == p.getNrZbor()) okZ == 1;
//					if (z.getnrZbor() == p.getNrZbor()) okZ = 1;
//				}
//
//				if (okZ == 0) cout << "ZBORUL NU ESTE ALOCAT PASAGERULUI IN ACEST MOMENT!";
//				else {
//					cout << "ORIGINE: " << t << t << t << t << z.getOrigine() << n;
//					cout << "DESTINATIE: " << t << t << t << t << z.getDestinatie() << n;
//					cout << "DISTANTA: " << t << t << t << t << z.getDistanta() << t << " miles" << n;
//					cout << "ORA DE PLECARE: " << t << t << t << z.getTimeOra() << ":" << z.getTimeMin() << n;
//					cout << "DURATA CALATORIEI: " << t << t << t << z.getDurata() << t << " minute" << n;
//					cout << "NUMELE COMPANIEI: " << t << t << t << z.getNumeCompanie() << n;
//					cout << "NUMARUL ZBORULUI: " << t << t << t << z.getnrZbor() << n;
//					cout << n;
//				}
//				dateinz.close();
//
//
//				
//			}
//			datein.close();	
//		}
//		
//
//	}
//}

void meniu_6()
{
			Pasager p;
			char nume[100];
			cout << "INTRODUCETI NUMELE PASAGERULUI: ";
			cin >> nume;
	
			char prenume[100];
			cout << "INTRODUCETI PRENUMELE PASAGERULUI: ";
			cin >> prenume;
	
			ifstream datein;
			datein.open("Pasager.txt", ios::in);
			if (!datein)
			{
				cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
			}
			else
			{
				string dummyline;
				getline(datein, dummyline);
				int ok = 0;
				while (!datein.eof() && ok == 0)
				{

					datein >> p;
					if (strcmp(p.getNume(), nume) == 0 && strcmp(p.getPrenume(), prenume) == 0) ok = 1;
				}

				cout << p;

				datein.close();
			}

			Zbor z;

			ifstream dateinz;
			dateinz.open("Zbor.txt", ios::in);
			if (!dateinz)
			{
				cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
			}
			else
			{
				string dummyline;
				getline(dateinz, dummyline);
				int ok = 0;
				while (!dateinz.eof() && ok == 0)
				{

					dateinz >> z;
					if (z.getnrZbor() == p.getNrZbor()) ok = 1;
					
				}
				if (ok == 0) cout << "ZBORUL NU ESTE ALOCAT PASAGERULUI IN ACEST MOMENT!";
								else {
									cout << "ORIGINE: " << t << t << t << z.getOrigine() << n;
									cout << "DESTINATIE: " << t << t << t << z.getDestinatie() << n;
									cout << "DISTANTA: " << t << t << t << z.getDistanta() << t << " miles" << n;
									cout << "ORA DE PLECARE: " << t << t << z.getTimeOra() << ":" << z.getTimeMin() << n;
									cout << "DURATA CALATORIEI: " << t << t << z.getDurata() << t << " minute" << n;
									cout << "NUMELE COMPANIEI: " << t << t << z.getNumeCompanie() << n;
									cout << "NUMARUL ZBORULUI: " << t << t << z.getnrZbor() << n;
									cout << n;
								}

				dateinz.close();
			}
}

int main()
{
	//meniu();
	//Bilet b;
	//cin >> b;

	//ofstream dateout;
	//dateout.open("bilet.txt", ios::out | ios::app);
	//if (!dateout)
	//	{
	//		cout << "FISIERUL NU A PUTUT FI GASIT"<<n;

	//	}
	//	else {
	//		cout << "FISIER CREAT CU SUCCES!"<<n;
	//		dateout << n;
	//		dateout << b;
	//		dateout.close();
	//	}

	/*ifstream datein;
	datein.open("bilet.txt", ios::in);
		if (!datein)
	{
		cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
	}
	else {
			Bilet b;
			string dummyline;
			getline(datein, dummyline);

			while (!datein.eof())
			{
				datein >> b;
				cout << b;
				cout << n << n;
			}
			
			datein.close();
		}*/

	//ADAUGARE FISIER AVION
	//ofstream dateout;
	//dateout.open("avion.txt", ios::out | ios::app);
	//if (!dateout)
	//	{
	//		cout << "FISIERUL NU A PUTUT FI GASIT"<<n;

	//	}
	//	else {
	//		Avion a;
	//		dateout << n;
	//		for (int i = 0; i < 3; i++)
	//		{
	//			cin >> a;
	//			//dateout << n;
	//			dateout << a;
	//		}
	//		dateout.close();
	//	}

	//AFISARE AVIOANE DIN FISIER
	/*ifstream datein;
	datein.open("avion.txt", ios::in);
	if (!datein)
	{
		cout << "FISIERUL DE INPUT NU S-A PUTUT DESCHIDE!";
	}
	else {
		Avion a;
		string dummyline;
		getline(datein, dummyline);

		while (!datein.eof())
		{
			datein >> a;
			cout << a;
			cout << n << n;
		}

		datein.close();
	}
	*/
	int id_meniu;

	//meniu();
	//cin >> id_meniu;
	bool quit = false;

	do {
		meniu();
		//string loc;
		cin >> id_meniu;
		cout << n;
		switch (id_meniu)
		{
		case 1: //DONE
			meniu_1();
			break;
			
		case 2: //DONE
			meniu_2();
			break;

		case 3: //DONE
			meniu_3();
			break;
		
		case 4: //DONE
			meniu_4();
			break;

		case 5: //DONE
			meniu_5();
			break;

		case 6:
			meniu_6();

			break;
		case 7:
			quit = true;
			break;
		}
	} while (!quit);


	return 0;
}