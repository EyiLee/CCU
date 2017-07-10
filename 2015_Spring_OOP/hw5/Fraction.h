#ifndef FRACTION
#define FRACTION
#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>

using namespace std;

class Fraction {
		int num;
		int denom;
		double value;
	public:
		Fraction();
		Fraction(int);
		Fraction(int ,int);
		int getNumerator() const { return num; }
		int getDenominator() const { return denom; }
		double decimalValue() const { return value; }
		void simplify();
		Fraction operator+(const Fraction &right);
		Fraction operator-(const Fraction &right);
		Fraction operator*(const Fraction &right);
		Fraction operator/(const Fraction &right);
		Fraction &operator+=(const Fraction &right);
		Fraction &operator-=(const Fraction &right);
		Fraction &operator*=(const Fraction &right);
		Fraction &operator/=(const Fraction &right);
		Fraction &operator++();
		Fraction operator++(int);
		Fraction &operator--();
		Fraction operator--(int);
		bool operator==(const Fraction &right);
		bool operator!=(const Fraction &right);
		bool operator>(const Fraction &right);
		bool operator<(const Fraction &right);
		bool operator>=(const Fraction &right);
		bool operator<=(const Fraction &right);
		friend ostream &operator<<(ostream &output, const Fraction &F);
};

#endif
