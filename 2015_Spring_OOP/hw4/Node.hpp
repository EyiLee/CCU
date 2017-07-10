#ifndef NODEFUC
#define NODEFUC
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>

using namespace std;

class Node {
		int data;
		Node *left;
		Node *right;
		void recursive(Node *);
		void show(Node *);
	public:
		Node();
		Node(int);
		~Node();
		void insert(int,int);
		void display();
		friend bool same_tree(Node *,Node *);
};
#endif
