#include<iostream>
#include<fstream>
#include<sstream>
#include<list>
#include"func.hpp"

using namespace std;
using namespace my_function;

int main( int argc, char *argv[] ) {

	fstream fp;

	int ans;

	ans = my_readfile(fp, argv);

	if( ans == -1 ) {
		cout << "Quit Program" << endl;
		return 0;
	}

	ans = fishing_licenses(fp);
	fp.close();

	if( ans == -1 ) {
		cout << "Input is error." << endl;
	}
	else {
		cout << "The maximum number of fishing licenses that can be sold is:" << ans << endl;
	}

	return 0;
}
