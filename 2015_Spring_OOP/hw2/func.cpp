#include"func.hpp"

namespace my_function {

	int my_readfile( fstream &fp, char *argv[] ) {
		
		string filename;

		if( argv[1] != NULL ) {
			filename = argv[1];
			fp.open(filename.c_str(), ifstream::in);
		}

		while( !fp.is_open() ) {
			cout << "Error! Cannot read file." << endl;
			cout << "Enter the File name again:";
			getline(cin, filename);
			if( filename.compare(0, 4, "quit") == 0 ) {
				return -1;
			}
			fp.open(filename.c_str(), ifstream::in);
		}

		if( fp.is_open() ) {
			cout << "File read success! \"" << filename  << "\"" << " has been read." << endl;
		}

		return 0;
	}

	int fishing_licenses( fstream &fp ) {

		list<int> p;

		int i;
		while( fp >> i ) {
			if( fp.eof() ) {
				break;
			}
			p.push_back(i);
		}

		if( p.size() != 9 ) {
			return -1;
		}

		double sum = 0;
		list<int>::iterator it;
	
		i = 0;
		for( it=p.begin(); it!=p.end(); ++it, ++i ) {
			if( it == p.begin() || it == --p.end() ) {
				sum += *it;
				continue;
			}
			if( i % 2 ) {
				sum += (*it)*4;
			} else {
				sum += (*it)*2;
			}
		}
		sum = sum * 200 / 3; // by Simpson¡¦s Rule
		sum *= 20; // avg depth is 20
		sum /= 1000; // 1 fish per 1000 cubic feet
		sum *= 0.75; // 25% remaining
		sum /= 20; // 20 fish per license

		return (int)sum;
	}

}
