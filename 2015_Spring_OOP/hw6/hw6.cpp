#include<iostream>
#include<cmath>
#include"MyShape.hpp"

using namespace std;

int main(void) {
	MyShape *theArray[5];
	for(int i = 0; i < 5; ++i) {
		int ans = 0;
		while( ans != 1 || ans != 2 ) {
			cout << "type \"1\" to make a Rectangle. " << endl;
			cout << "type \"2\" to make a Circle " << endl;
			cin >> ans;
			if( ans == 1 ) {
				int l, w;
				cout << "enter your [length] [width] to make a Rectangle." << endl;
				cin >> l >> w;
				Rectangle *rec = new Rectangle(l,w);
				theArray[i] = rec;
				break;
			}
			if( ans == 2 ) {
				int d;
				cout << "enter your [diameter] to make a Circle." << endl;
				cin >> d;
				Circle *cir = new Circle(d);
				theArray[i] = cir;
				break;
			}
			cout << "\"" << ans << "\" is undefined input !" << endl;
		}
	}
	for(int i = 0; i < 5; ++i) {
		cout << i << " : ";
		theArray[i]->showShape();
		cout << " = " << theArray[i]->findArea() << endl;
		delete theArray[i];
	}
	return 0;
}
