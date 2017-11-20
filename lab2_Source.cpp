#include <iostream>
#include "lab2_neuron.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <time.h>

using namespace std;

void wczytaj_dane(Neuron tablica[],double **tw);
double korekcja_w1(double p,Neuron n1);
double korekcja_w2(double p,Neuron n1);


int main(){
	srand(time(NULL));
	Neuron tab_n[2];
	//Neuron n1;
	for(int t=0;t<2;t++)
		tab_n[t].losuj_wagi();//20x20 wag
	//n1.losuj_wagi();
	//int n;
	//cout<<"Podaj ilosc danych do 20: ";
	//cin>>n;
	//cout<<endl;
	cout<<"WAGI poczatkowe: "<<endl;
	for (int l=0;l<2;l++){
		cout<<"Neuron nr: "<<l<<endl;
		for(int j=0;j<20;j++){
		cout<<tab_n[l].tab_waga[j]<<endl;
		}
	}
	cout<<"#################   Wczytuje dane  ##################"<<endl;
	int i=1;
	for(int e=0;e<500;e++){
		cout<<"__________________________ EPOKA "<<e<<"_________________________"<<endl;
		
		i++;
		for (int k=0;k<2;k++)
		{
		tab_n[k].wczytaj_dane(k,e);
		}
		
	}
system("PAUSE");
}


/*
double korekcja_w1(double r,Neuron n1){
	//cout<<"Funkcja aktywacji: "<<n1.fun_act(n1.suma());
	double c=0.1;//stala uczenia
	double dw1=c*r*n1.get_x1();//o ile sie zmieni waga1
	//cout<<"  W1 przed: "<<n1.w1;
	n1.w1=n1.w1+dw1;
	//cout<<"  W1 po: "<<n1.w1;
		return  dw1;
}
double korekcja_w2(double r,Neuron n1){
	//cout<<"Funkcja aktywacji: "<<n1.fun_act(n1.suma());
	double c=0.2;//stala uczenia
	double dw2=c*r*n1.get_x2();//o ile sie zmieni waga2
	//cout<<"  W2 przed: "<<n1.w2;
	n1.w2=n1.w2+dw2;
	//cout<<"  W2 po: "<<n1.w2<<endl;
		return  dw2;
}*/
/*
	bool warunek = true;
	int i=1;
	while(warunek){
		cout<<"__________________________ EPOKA "<<i<<"_________________________"<<endl;
		int licz=0;
		for(int j=0;j<20;j++)
		{
			//cout<<" X1 przed : "<<n1.get_x1()<<endl;
			//cout<<" X2 przed : "<<n1.get_x2()<<endl;
			tab_n[j].set_x1(tab_wejscia[j][0]);
			
			//n1.set_x2(tab_wejscia[j][1]);
			
			//cout<<" X1 po : "<<n1.get_x1()<<endl;
			//cout<<" X2 po : "<<n1.get_x2()<<endl;
						
			if((fabs(tab_n[j].fun_act(tab_n[j].suma())-tab_wejscia[j][2])>0.99)||(fabs(tab_wejscia[j][2]-tab_n[j].fun_act(tab_n[j].suma()))<0.1))
			{			
				licz++;
				cout<<"Funkcja aktywacji: "<<tab_n[j].fun_act(tab_n[j].suma())<<"  Rekord nauczony !"<<endl;	
				if(licz==20){
					cout<<"Neuron nauczyl sie za "<<i+1<<" razem"<<endl;
					warunek=false;}
			}
			else
			{	cout<<"Funkcja aktywacji: "<<tab_n[j].fun_act(tab_n[j].suma());
				korekcja_w1(tab_wejscia[j][2]-tab_n[j].fun_act(tab_n[j].suma()),tab_n[j]);
				korekcja_w1(tab_wejscia[j][2]-tab_n[j].fun_act(tab_n[j].suma()),tab_n[j]);
				tab_n[j].set_w1(tab_n[j].get_w1()+korekcja_w1(tab_wejscia[j][2]-tab_n[j].fun_act(tab_n[j].suma()),tab_n[j]));
				tab_n[j].set_w2(tab_n[j].get_w2()+korekcja_w2(tab_wejscia[j][2]-tab_n[j].fun_act(tab_n[j].suma()),tab_n[j]));
				cout<<" w1: "<<tab_n[j].get_w1()<<" , w2: "<<tab_n[j].get_w2()<<endl;
				
			}
		}
		i++;
	}*/