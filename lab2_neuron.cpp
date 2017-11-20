#include <iostream>
#include <time.h>
#include "lab2_neuron.h"
#include <fstream>
#include <string>

using namespace std;



double Neuron::fun_act(double suma){
	return (2/(1+exp(-2*0.2*suma)) - 1); //B - wspolczynnik uczenia (0.1 lub 0.5), tangens hiperboliczny - zwraca wartosci od -1 do 1
}
void Neuron::losuj_wagi(){
		for(int i=0;i<20;i++)
			tab_waga[i]=((rand() % 1000)/1000.00);
}
double Neuron::suma(){
	double sum=0;
	
	for(int i=0;i<20;i++)
	{
		sum=sum+tab_x[i]*tab_waga[i];
	}

	return sum;
}
void Neuron::wczytaj_dane(int nr_neuronu,int l_epok){ // nie wiem co tu i jak ????????
	
	int nr_lini=0;
	string linia,pom;
	fstream plik;	
	float r;
	int l_nauczd=0,l_nauczm=0;
	plik.open("LAB2_dane.txt", ios::in);
	bool war1=true;
	if(plik.good()==false)
	{
		cout<<"Blad wczytywania pliku !!!"<<endl;
		exit(0);
	}
	cout<<endl<<"#################   Wynik funkcji aktwacji  - neuron "<<nr_neuronu<<" ##################"<<endl;
	while(getline(plik,linia))
	{ 
		cout<<"Rekord: "<<nr_lini;
		for(unsigned int i=0; i<20;i++)
				{	
					pom = linia.substr(i,1);
					tab_x[i]=atof(pom.c_str());
				}
		pom = linia.substr(20,2);
		oczekiwana[nr_lini] = atof(pom.c_str());
		//cout<<"Wartosc oczekiwana: "<<oczekiwana[nr_lini]<<endl;
		r = oczekiwana[nr_lini]-fun_act(suma());		
		//cout<<"Funkcja aktywacji: "<<fun_act(suma())<<endl;
		if(((nr_neuronu==0)&&(fun_act(suma())>0.9))||((nr_neuronu==1)&&(fun_act(suma())<-0.9)))
			{			
				cout<<" Funkcja aktywacji: "<<fun_act(suma())<<" Nauczyl sie "<<endl;	
				l_nauczd++;
				if(l_nauczd==20){
					cout<<" Neurony nauczyly sie za "<<l_epok<<" razem"<<endl;
					break;
				}
			}
		else
		{
			cout<<" Funkcja aktywacji: "<<fun_act(suma())<<endl;
			korekcja_wag(r);
		} 

		nr_lini++;
		if(nr_lini==20){break;}
	}
	
}
void Neuron::korekcja_wag(float r){
	double c=0.2;//stala uczenia
	float dw1;
	for(int i=0;i<20;i++){
		dw1=c*r*tab_x[i];//o ile sie zmieni waga
		//cout<<"  Waga przed: "<<tab_waga[i]<<" ==> ";
		tab_waga[i]=tab_waga[i]+dw1;
		//cout<<"  Waga po: "<<tab_waga[i]<<endl;
	}
}



/*if((nr_neuronu==0)&&(fun_act(suma())>0.95))
			{			
				cout<<"Funkcja aktywacji: "<<fun_act(suma())<<"  Du¿a litera !";	
				l_nauczd++;
				if(l_nauczd==10){
					cout<<" Neuron nauczyl sie za "<<l_epok+1<<" razem"<<endl;
					war=false;}
			}
		else if((nr_neuronu==1)&&(fun_act(suma())<-0.95))
		{
			cout<<"Funkcja aktywacji: "<<fun_act(suma())<<"  Mala litera !";	
				l_nauczm++;
				if(l_nauczm==10){
					cout<<" Neuron nauczyl sie za "<<l_epok+1<<" razem"<<endl;
					war1=false;}
		}
			else
			{	
				cout<<"Funkcja aktywacji: "<<fun_act(suma());
				korekcja_wag(r);
			}
	*/