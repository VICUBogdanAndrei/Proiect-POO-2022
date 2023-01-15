#define _CRT_SECURE_NO_WARNINGS
#include "Pasager.h"
#include "Zbor.h"
#include "Avion.h"
#include "Bilet.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

void meniu_1()
{
	ifstream datein;
	datein.open("zbor.txt", ios::in);
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