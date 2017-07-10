#ifndef COINSFUNC
#define COINSFUNC
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<cstdlib>

using namespace std;

class Coins {
		int dollars, cents;
		int q, d, n, p;
		void extract(double &);
		void compute(int &, int &);
	public:
		Coins(double &);
		void display();
		int get_dollars() const { return dollars; }
		int get_cents() const { return cents; }
		int get_q() const { return q; }
		int get_d() const { return d; }
		int get_n() const { return n; }
		int get_p() const { return p; }
};
#endif
