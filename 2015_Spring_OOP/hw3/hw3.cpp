#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<cstdlib>
#include"coins.hpp"

using namespace std;

int main(int argc ,char **argv) {
	double num = atof(argv[1]);
	class Coins coins = Coins(num);
	coins.display();
	return 0;
}
