#ifndef LNLISTFUC
#define LNLISTFUC
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>

using namespace std;

struct cNode {
	int data;
	cNode *next;
};

class LnList {
		cNode *head;
	public:
		LnList();
		LnList(int);
		~LnList(); 
		void insert(int);
		bool find(int);
		bool remove(int);
		void show();
};
#endif
