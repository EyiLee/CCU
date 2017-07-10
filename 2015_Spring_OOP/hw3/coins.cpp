#include"coins.hpp"

Coins::Coins(double &x) {
	extract(x);
	compute(dollars, cents);
}

void Coins::extract(double &x) {
	stringstream temp;
	temp << fixed << setprecision(3) << x;
	string num;
	temp >> num;
	size_t pos = num.find('.');
	string num1 = num.substr(0, pos);
	string num2 = num.substr(pos + 1);
	dollars = atoi(num1.c_str());
	cents = atoi(num2.c_str());
	if(cents % 10) {
		cerr << "Input error. There should only have two numbers after decimal point." << endl;
		exit(0);
	} else {
		cents /= 10;
	}
}

void Coins::compute(int &a, int &b) {
	q = 0, d = 0, n = 0, p = 0;
	q = b/25;
	b %= 25;
	d = b/10;
	b %= 10;
	n = b/5;
	b %= 5;
	p = b;
	q += a*4;
}

void Coins::display() {
	cout << q << " quarters, " << d <<" dimes, " << n << " nickels, " << p << " pennies" << endl;
}
