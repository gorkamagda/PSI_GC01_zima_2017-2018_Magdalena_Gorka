#include <iostream>
#include <time.h>
#include "LAB1_perceptron.h"
using namespace std;

void Neuron::set_w1( double n1 )
    {
        w1 = n1;
    }
void Neuron::set_w2( double n2 )
    {
        w2 = n2;
    }
void Neuron::set_x1( double a1 )
    {
        x1 = a1;
    }
void Neuron::set_x2( double a2 )
    {
        x2 = a2;
    }
double Neuron::get_w1(){
		return w1;
	}
	double Neuron::get_w2(){
		return w2;
	}
	double Neuron::get_x1(){
		return x1;
	}
	double Neuron::get_x2(){
		return x2;
	}
double Neuron::fun_act(double suma){
	return (2/(1+exp(-2*0.5*suma)) - 1); //B - wspolczynnik uczenia (0.1 lub 0.2 lub 0.5), tangens hiperboliczny - zwraca wartosci od -1 do 1, Sigmoidalna funkcja bipolarna (tangens hiperboliczny)
}
void Neuron::losuj_wagi(){
		srand(time(NULL));
			double w_1=(rand() % 100);//przedzial wag dla uproszczenia od -2 do 2
			double w_2=(rand() % 100);
			set_w1(w_1/100);
			set_w2(w_2/100);
	}
double Neuron::suma(){
	double sum;
	sum=(get_x1()*get_w1())+(get_x2()*get_w2());
	return sum;
}
