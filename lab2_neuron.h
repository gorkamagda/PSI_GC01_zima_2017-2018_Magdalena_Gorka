class Neuron{	
public:
	double tab_waga[20];
	double tab_x[20];
	double oczekiwana[20];
public:

	double fun_act(double);
	void losuj_wagi();	
	double suma();
	void wczytaj_dane(int,int);
	void korekcja_wag(float);
};