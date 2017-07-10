#include"Fraction.h"

int gcd(int a, int b) {
	if( a == 0 )
		return b;
    return gcd(b % a, a);
}

Fraction::Fraction() {
	num = 0;
	denom = 1;
	value = 0;
}

Fraction::Fraction(int n) {
	num = n;
	denom = 1;
	value = n;
}

Fraction::Fraction(int n, int d) {
	num = n;
	if( d == 0 ) {
		cerr << "denominator can't be zero." << endl;
		exit(0);
	}
	denom = d;
	value = (double)n / (double)d;
	simplify();
}

void Fraction::simplify() {
	if( num < 0 && denom < 0 ) {
		num *= -1;
		denom *= -1;
	}
	else if( denom < 0 ) {
		num *= -1;
		denom *= -1;
	}
	int g = gcd(abs(num) ,abs(denom));
	num /= g;
	denom /= g;
	value = (double)num / (double)denom;
}

Fraction Fraction::operator+(const Fraction &right) {
	Fraction tmp;
	tmp.num = this->num * right.denom + right.num * this->denom;
	tmp.denom = this->denom * right.denom;
	tmp.simplify();
	return tmp;
}

Fraction Fraction::operator-(const Fraction &right) {
	Fraction tmp;
	tmp.num = this->num * right.denom - right.num * this->denom;
	tmp.denom = this->denom * right.denom;
	tmp.simplify();
	return tmp;
}

Fraction Fraction::operator*(const Fraction &right) {
	Fraction tmp;
	tmp.num = this->num * right.num;
	tmp.denom = this->denom * right.denom;
	tmp.simplify();
	return tmp;
}

Fraction Fraction::operator/(const Fraction &right) {
	if( right.num == 0 ) {
		cerr << "denominator can't be zero." << endl;
		exit(0);
	}
	Fraction tmp;
	tmp.num = this->num * right.denom;
	tmp.denom = this->denom * right.num;
	tmp.simplify();
	return tmp;
}

Fraction & Fraction::operator+=(const Fraction &right) {
	int n, d;
	n = this->num * right.denom + right.num * this->denom;
	d = this->denom * right.denom;
	this->num = n;
	this->denom = d;
	this->simplify();
	return *this;
}

Fraction & Fraction::operator-=(const Fraction &right) {
	int n, d;
	n = this->num * right.denom - right.num * this->denom;
	d = this->denom * right.denom;
	this->num = n;
	this->denom = d;
	this->simplify();
	return *this;
}

Fraction & Fraction::operator*=(const Fraction &right) {
	int n, d;
	n = this->num * right.num;
	d = this->denom * right.denom;
	this->num = n;
	this->denom = d;
	this->simplify();
	return *this;
}

Fraction & Fraction::operator/=(const Fraction &right) {
	int n, d;
	if( right.num == 0 ) {
		cerr << "denominator can't be zero." << endl;
		exit(0);
	}
	n = this->num * right.denom;
	d = this->denom * right.num;
	this->num = n;
	this->denom = d;
	this->simplify();
	return *this;
}

Fraction & Fraction::operator++() {
	this->num += this->denom;
	return *this;
}

Fraction Fraction::operator++(int x) {
	Fraction tmp;
	tmp.num = this->num;
	tmp.denom = this->denom;
	tmp.value = this->value;
	this->num += this->denom;
	return tmp;

}

Fraction & Fraction::operator--() {
	this->num -= this->denom;
	return *this;
}

Fraction Fraction::operator--(int x) {
	Fraction tmp;
	tmp.num = this->num;
	tmp.denom = this->denom;
	tmp.value = this->value;
	this->num -= this->denom;
	return tmp;
}

bool Fraction::operator==(const Fraction &right) {
	return this->num * right.denom == this->denom * right.num;
}

bool Fraction::operator!=(const Fraction &right) {
	return this->num * right.denom != this->denom * right.num;
}

bool Fraction::operator>(const Fraction &right) {
	return this->num * right.denom < this->denom * right.num;
}

bool Fraction::operator<(const Fraction &right) {
	return this->num * right.denom < this->denom * right.num;
}

bool Fraction::operator>=(const Fraction &right) {
	return this->num * right.denom >= this->denom * right.num;
}

bool Fraction::operator<=(const Fraction &right) {
	return this->num * right.denom <= this->denom * right.num;
}

ostream &operator<<(ostream &output, const Fraction &F) {
	output << F.getNumerator() << "/" << F.getDenominator();
	return output;
}
