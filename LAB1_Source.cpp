#include <iostream>
#include "LAB1_perceptron.h"
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

void wczytaj_dane(Neuron n1,double **tw, int n);
double korekcja_w1(double p,Neuron n1);
double korekcja_w2(double p,Neuron n1);


int main(){
	Neuron n1;
	n1.losuj_wagi();
	int n;
	cout<<"Podaj ilosc danych do 20: ";
	cin>>n;
	cout<<endl;
	double **tab_wejscia = new double *[n];
	for(int i=0; i<n;i++){
		tab_wejscia[i]=new double [3];
	}
	cout<<"WAGI poczatkowe: ";
	cout<<n1.get_w1()<<" "<<n1.get_w2()<<endl;
	
	wczytaj_dane(n1,tab_wejscia,n);
	bool warunek = true;
	int i=1;
	while(warunek){
		cout<<"__________________________ EPOKA "<<i<<"_________________________"<<endl;
		int licz=0;
		for(int j=0;j<n;j++)
		{
			//cout<<" X1 przed : "<<n1.get_x1()<<endl;
			//cout<<" X2 przed : "<<n1.get_x2()<<endl;
			n1.set_x1(tab_wejscia[j][0]);
			n1.set_x2(tab_wejscia[j][1]);
			//cout<<" X1 po : "<<n1.get_x1()<<endl;
			//cout<<" X2 po : "<<n1.get_x2()<<endl;
						
			if((fabs(n1.fun_act(n1.suma())-tab_wejscia[j][2])>0.99)||(fabs(tab_wejscia[j][2]-n1.fun_act(n1.suma()))<0.1))
			{			
				licz++;
				cout<<"Funkcja aktywacji: "<<n1.fun_act(n1.suma())<<"  Rekord nauczony !"<<endl;	
				if(licz==n){
					cout<<"Neuron nauczyl sie za "<<i+1<<" razem"<<endl;
					warunek=false;}
			}
			else
			{	cout<<"Funkcja aktywacji: "<<n1.fun_act(n1.suma());
				korekcja_w1(tab_wejscia[j][2]-n1.fun_act(n1.suma()),n1);
				korekcja_w1(tab_wejscia[j][2]-n1.fun_act(n1.suma()),n1);
				n1.set_w1(n1.get_w1()+korekcja_w1(tab_wejscia[j][2]-n1.fun_act(n1.suma()),n1));
				n1.set_w2(n1.get_w2()+korekcja_w2(tab_wejscia[j][2]-n1.fun_act(n1.suma()),n1));
				cout<<" w1: "<<n1.get_w1()<<" , w2: "<<n1.get_w2()<<endl;
				
			}
		}
		i++;
	}
system("PAUSE");
}

void wczytaj_dane(Neuron n1,double **tw, int n){
	
	int z=0,j=0,nr_lini=0;
	string linia,pom;
	fstream plik;	

	plik.open("LAB1_dane.txt", ios::in);

	if(plik.good()==false)
	{
		cout<<"Blad wczytywania pliku !!!"<<endl;
		exit(0);
	}
	
	while(getline(plik,linia))
	{ 
		for(unsigned int i=0; i < linia.length();i++)
				{
					if((linia[i]==' ') && (j==0))
					{
						pom.insert(0,linia,z,i);				
						tw[nr_lini][0]=(atof(pom.c_str()));
						j++;
						z=i;
						pom.clear();
					}
					else
						if((linia[i]==' ') && (j==1))
					{
						pom.insert(0,linia,z,i-z);
						tw[nr_lini][1]=(atof(pom.c_str()));
						j++;
						z=i;
						pom.clear();
					}
					else
					if(i==linia.length()-1 && j==2)
					{
						pom.insert(0,linia,z,i-z+1);
						tw[nr_lini][2]=atoi(pom.c_str());
						j=0;
						z=0;
						pom.clear();
					}
				}
		nr_lini++;
		if(nr_lini==n){break;}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++)
				cout<< tw[i][j]<<"  ";
		cout<<endl;
		}
}
double korekcja_w1(double r,Neuron n1){
	//cout<<"Funkcja aktywacji: "<<n1.fun_act(n1.suma());
	double c=0.5;//stala uczenia
	double dw1=c*r*n1.get_x1();//o ile sie zmieni waga1
	//cout<<"  W1 przed: "<<n1.w1;
	n1.w1=n1.w1+dw1;
	//cout<<"  W1 po: "<<n1.w1;
		return  dw1;
}
double korekcja_w2(double r,Neuron n1){
	//cout<<"Funkcja aktywacji: "<<n1.fun_act(n1.suma());
	double c=0.5;//stala uczenia
	double dw2=c*r*n1.get_x2();//o ile sie zmieni waga2
	//cout<<"  W2 przed: "<<n1.w2;
	n1.w2=n1.w2+dw2;
	//cout<<"  W2 po: "<<n1.w2<<endl;
		return  dw2;
}