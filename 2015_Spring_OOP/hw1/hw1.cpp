#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;

struct Mul {
	int begin;
	int count[10];
	int max;
	string maxp;
	string prep;
};

void subMultition(string num, int n, int len, Mul *mul, int tot) {
	if(n < 0) {
		string temp;
		int pos = 0;
		int ans = 1;
		mul->prep.clear();

		for(int i = 0; i < mul->begin; i++) {
			temp = num.substr(pos, mul->count[i]);
			mul->prep.append(temp);
			mul->prep.append(" * ");
			ans *= atoi(temp.c_str());
			pos += mul->count[i];
		}
		temp = num.substr(pos);
		mul->prep.append(temp);
		ans *= atoi(temp.c_str());

		if(ans > mul->max) {
			mul->max = ans;
			mul->maxp.clear();
			mul->maxp.append(mul->prep);
		}
	} else {
		for(int i = 1; i < len; i++) {
			if(tot + i < len) {
				mul->count[n] = i;
				subMultition(num, n-1, len, mul, tot+i);
			} else {
				break;
			}
		}
	}
}

void optimalMultition() {
	Mul *mul = new Mul;
	string num;
	int n,len;	// sign number,string length
	cin >> num >> n;
	len = num.length();
	
	if(n >= len) {
		cerr << "Multiplication sign is too many." << endl;
	} else if (n <= 0) {
		cerr << "Multiplication sign is too less." << endl;
	} else if(len == 10) {
		long big = atol(num.c_str());
		if(big > 2147483647) {
			cerr << "The input interger is too large." << endl;
		}
	} else if(len > 10) {
		cerr << "The input interger is too large." << endl;
	} else {
		for(int i = 0; i < len; i++) {
			mul->count[i] = 0;
		}
		mul->begin = n;
		subMultition(num, n-1, len, mul, 0);
		cout << "Maximum product : " << mul->max << " = " << mul->maxp << endl;
	}
	delete mul;
}

int main() {
	char check;
	do {
		cout << "Enter the number followed by the order : ";
		optimalMultition();
		cout << "Continue? Y/n(anykey) : ";
	} while(cin >> check && (check == 'Y' || check == 'y'));
	return 0;
}
