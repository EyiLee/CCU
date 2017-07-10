#include <iostream>
#include "Fraction.h"

using namespace std;

int main(int argc, char **argv) {
    
    Fraction f1 = Fraction(2, 3),
             f2 = Fraction(5, 6),
             t1 = Fraction(-16, 28),
             t2 = Fraction(36, -63);
	
	cout << "f1 = 2/3 , f2 = 5/6" << endl;

	cout << "f1.getNumerator() = " << f1.getNumerator() << endl;
	cout << "f1.getDenominator() = " << f1.getDenominator() << endl;
	cout << "f1.decimalValue() = " << f1.decimalValue() << endl << endl;
	cout << "f2.getNumerator() = " << f2.getNumerator() << endl;
	cout << "f2.getDenominator() = " << f2.getDenominator() << endl;
	cout << "f2.decimalValue() = " << f2.decimalValue() << endl << endl;

	cout << "f1 + f2 = " << f1 + f2 << endl;
	cout << "f1 - f2 = " << f1 - f2 << endl;
	cout << "f1 * f2 = " << f1 * f2 << endl;
	cout << "f1 / f2 = " << f1 / f2 << endl << endl;

	cout << "f1 += f2 , f1 = " << ( f1 += f2 ) << endl;
	cout << "f1 -= f2 , f1 = " << ( f1 -= f2 ) << endl;
	cout << "f1 *= f2 , f1 = " << ( f1 *= f2 ) << endl;
	cout << "f1 /= f2 , f1 = " << ( f1 /= f2 ) << endl << endl;

	cout << "f1++ = " << f1++ << endl;
	cout << "f1 = " << f1 << endl << endl;
	cout << "++f1 = " << ++f1 << endl;
	cout << "f1 = " << f1 << endl << endl;
	cout << "f1-- = " << f1-- << endl;
	cout << "f1 = " << f1 << endl << endl;
	cout << "--f1 = " << --f1 << endl;
	cout << "f1 = " << f1 << endl << endl;

	cout << "f1 == f2 : " << ( f1 == f2 ) << endl;
	cout << "f1 != f2 : " << ( f1 != f2 ) << endl;
	cout << "f1 > f2 : " << ( f1 > f2 ) << endl;
	cout << "f1 < f2 : " << ( f1 < f2 ) << endl;
	cout << "f1 >= f2 : " << ( f1 >= f2 ) << endl;
	cout << "f1 <= f2 : " << ( f1 <= f2 ) << endl;

    return 0;
}
