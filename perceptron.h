class Neuron{	
private:
	double x1;
	double x2;
public:
	double w1;
	double w2;
public:

	double fun_act(double );
	void losuj_wagi();
	void set_w1( double );
	void set_w2( double );
	void set_x1( double );
	void set_x2( double );
	double get_w1(  );
	double get_w2(  );
	double get_x1(  );
	double get_x2(  );
	double suma();
};