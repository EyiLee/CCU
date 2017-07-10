#ifndef LISTFUC
#define LISTFUC
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>

using namespace std;

class List {
		float *dynamic_array;
		int size;
		int capacity;
		void expand();
	public:
		List();
		List(float);
		~List();
		void insert_at(int , float);
		void remove_at(int);
		void value_show();
		bool find(int);
		float value_at(int);
};
#endif
