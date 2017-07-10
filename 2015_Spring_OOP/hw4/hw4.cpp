#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include"List.hpp"
#include"LnList.hpp"
#include"Node.hpp"

using namespace std;

void selectmode();
void doList();
void doLnList();
void doSametree();

int main(int argc,char **argv) {
	string cms;
	stringstream args;

	selectmode();
	while( getline(cin,cms) ) {
		args.clear();
		args << cms;
		args >> cms;
		if( atoi(cms.c_str()) == 1 ) {
			doList();
		}
		else if( atoi(cms.c_str()) == 2 ) {
			doLnList();
		}
		else if( atoi(cms.c_str()) == 3 ) {
			doSametree();
		}
		else if( atoi(cms.c_str()) == 4 ) {
			break;
		}
		selectmode();
	}

	cout << "exit program." << endl;
	return 0;
}

void selectmode() {
	cout << "1. List (Part A 使用動態陣列儲存、查詢、刪除元素)" << endl;
	cout << "2. LnList (Part B 使用linked list儲存、查詢、刪除元素)" << endl;
	cout << "3. Sametree (Part C 判別兩個TREE是否結構相同)" << endl;
	cout << "4. exit program" << endl;
}

void doList() {
	cout << "use [ insert | find | remove ] [ index ] [ value ] to run the process." << endl;
	cout << "type \"exit\" to ext the process." << endl;

	string cms;
	stringstream args;

	int index;
	float value;
	class List l = List();
	l.value_show();

	while( getline(cin,cms) ) {
		args.clear();
		args << cms;
		args >> cms;
		if( cms.compare("insert") == 0 ) {
			args >> cms;
			index = atoi(cms.c_str());
			args >> cms;
			value = atof(cms.c_str());
			l.insert_at(index,value);
			l.value_show();
		}
		else if( cms.compare("find") == 0 ) {
			args >> cms;
			index = atoi(cms.c_str());
			if( l.find(index) ) {
				cout << l.value_at(index) << endl;
			}
			else {
				cout << "not found" << endl;
			}
		}
		else if( cms.compare("remove") == 0 ) {
			args >> cms;
			index = atoi(cms.c_str());
			l.remove_at(index);
			l.value_show();
		}
		else if( cms.compare("exit") == 0 ) {
			return;
		}
	}
}

void doLnList() {
	cout << "use [ insert | find | remove ] [ value ] to run the process." << endl;
	cout << "type \"exit\" to ext the process." << endl;

	string cms;
	stringstream args;

	int value;
	class LnList l = LnList();
	l.show();

	while( getline(cin,cms) ) {
		args.clear();
		args << cms;
		args >> cms;
		if( cms.compare("insert") == 0 ) {
			args >> cms;
			value = atof(cms.c_str());
			l.insert(value);
			l.show();
		}
		else if( cms.compare("find") == 0 ) {
			args >> cms;
			value = atoi(cms.c_str());
			if( l.find(value) ) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		else if( cms.compare("remove") == 0 ) {
			args >> cms;
			value = atoi(cms.c_str());
			l.remove(value);
			l.show();
		}
		else if( cms.compare("exit") == 0 ) {
			return;
		}
	}

}

void doSametree() {
	cout << "use [ done | ainsert | binsert ] [ value ] [ index ] to run the process." << endl;
	cout << "type \"exit\" to ext the process." << endl;

	string cms;
	stringstream args;

	int index, value;
	class Node *l = new Node(),*r = new Node();

	while( getline(cin,cms) ) {
		args.clear();
		args << cms;
		args >> cms;
		if( cms.compare("ainsert") == 0 ) {
			args >> cms;
			value = atoi(cms.c_str());
			args >> cms;
			index = atoi(cms.c_str());
			l->insert(value,index);
			l->display();
		}
		else if( cms.compare("binsert") == 0 ) {
			args >> cms;
			value = atoi(cms.c_str());
			args >> cms;
			index = atoi(cms.c_str());
			r->insert(value,index);
			r->display();
		}
		else if( cms.compare("done") == 0 ) {
			if( same_tree(l,r) ) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
		}
		else if( cms.compare("exit") == 0 ) {
			return;
		}
	}

}

