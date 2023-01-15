#define _CRT_SECURE_NO_WARNINGS
#define n '\n'
#define t '\t'

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

using namespace std;

void meniu()
{
	cout << n << n;
	cout << "-------------------------------------------------------" << n;
	cout << "------------ TICKETING APP - FLIGHT TICKET ------------" << n;
	cout << "-------------------------------------------------------" << n;
	cout << "--------------------->>> MENIU <<<---------------------" << n;
	cout << "-------------------------------------------------------" << n;
	cout << "-----    I. AFISARE ZBORURI DISPONIBILE ---------------" << n;
	cout << "-----   II. VERIFICARE REZERVARE ----------------------" << n;
	cout << "-----  III. CREARE O NOUA REZERVARE -------------------" << n;
	cout << "-----   IV. SCHIMBARE DESTINATIE ----------------------" << n;
	cout << "-----    V. VERIFICARE DISPONIBILITATE LOCURI ---------" << n;
	cout << "-----   VI. VERIFICARE EXISTENTA ZBOR DORIT -----------" << n;
	cout << "-----  VII. AFISARE ITINERARIU ------------------------" << n;
	cout << "----- VIII. EXIT --------------------------------------" << n;
	cout << "-------------------------------------------------------" << n;
	cout << n;
	cout << n;
	cout << "INTRODUCETI NUMARUL DIN MENIU CORESPUNZATOR CERINTEI: ";
	//cout << n;
}

int main()
{
	int id_meniu;

	bool quit = false;

	do {
		meniu();
		cin >> id_meniu;
		cout << n;
		switch (id_meniu)
		{
		case 1:
			//meniu_1();
			break;
		case 2:
			//meniu_2();

			break;
		case 3:


			break;
		case 4:


			break;
		case 5:


			break;
		case 6:


			break;
		case 7:


			break;
		case 8:
			quit = true;
			break;
		}
	} while (!quit);




	return 0;
}