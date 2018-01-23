#include "LAB2_Perceptron.h"
#include <cstdlib>
#include <iostream>
	using namespace std;


Perceptron::Perceptron()
{
	this->ilosc_wejsc = 20; 
	this->wsp_nauki = 0.05;

	this->Litery = new int*[20];
	for (int i = 0; i < 20; i++)
		Litery[i] = new int[72];

	this->wagi = new float[72];
	for (int i = 0; i < 72; i++)
	{
		this->wagi[i] = (float)rand() / (float)RAND_MAX;
	}

	wczytywanie_danych_z_pliku();
}

void Perceptron::wczytywanie_danych_z_pliku()
{
	fstream plik;	
	plik.open("Litery.txt");	
	if (!plik.good()) 
	{
		cout << "Blad otwarcia" << endl;
		system("PAUSE");
	}
	while (!plik.eof()) 
	{
		for (int i = 0; i < ilosc_wejsc; i++)
		{
			for (int j = 0; j < 72; j++)
			{
				plik >> this->Litery[i][j]; 
			}
			plik >> this->wyniki[i]; 
		}
	}
	plik.close();
}



float Perceptron::f_sumowania(int i)
{	
	float suma = 0;
	for (int j = 0; j < 72; j++)
	{
		suma += this->Litery[i][j] * this->wagi[j];
	}
	return suma;
}

void Perceptron::ucze()
{
	float local_err;	
	float global_err = 0;	
	int ID_litery;	
	float nauczony = 1.6; 
	int numer_epoki = 0;
	do
	{
		global_err = 0;
		for (ID_litery = 0; ID_litery < this->ilosc_wejsc; ID_litery++)
		{
			local_err = this->wyniki[ID_litery] - f_sumowania(ID_litery);
			for (int i = 0; i < 72; i++)
			{
				this->wagi[i] += this->wsp_nauki * local_err * this->Litery[ID_litery][i];
			}

			global_err += (local_err*local_err);
		}
		numer_epoki++;
	} while (global_err > nauczony); 
	cout << "Ilosc sesji nauczania = " << numer_epoki << endl;
}


void Perceptron::sprawdzam(int tab[])
{
	
	float suma = 0;
	float local_err = 0;
	float global_err = 0;
	float nauczony_aktywacji = 1.5;
	for (int i = 0; i < 72; i++)
	{
		suma += tab[i] * this->wagi[i]; 
	}
	local_err = 1 - suma; 
	global_err = local_err*local_err;	

	if (global_err < nauczony_aktywacji)	
		this->wynik = true;
	else
		this->wynik = false; 

	if (this->wynik == true)
		cout << "mala litera!" << endl << endl;
	else
		cout << "duza litera!" << endl << endl;
}


Perceptron::~Perceptron()
{
}