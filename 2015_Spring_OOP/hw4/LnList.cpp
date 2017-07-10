#include"LnList.hpp"

using namespace std;

LnList::LnList() {
	head = NULL;
}

LnList::LnList(int x) {
	head = new cNode;
	head->data = x;
	head->next = NULL;
}

LnList::~LnList() {
	cNode *ptr = head,*pre = NULL;
	while( ptr != NULL ) {
		pre = ptr;
		ptr = ptr->next;
		delete ptr;
	}
}

void LnList::insert(int value) {
	cNode *ptr = head,*pre = NULL;
	while( ptr != NULL ) {
		pre = ptr;
		ptr = ptr->next;
	}
	if( ptr == NULL && pre == NULL ) {
		ptr = new cNode;
		ptr->data = value;
		ptr->next = NULL;
		head = ptr;
	}
	else if ( ptr == NULL ) {
		pre->next = new cNode;
		pre->next->data = value;
		pre->next->next = NULL;
	}
}

bool LnList::find(int value) {
	cNode *ptr = head;
	while( ptr != NULL ) {
		if( ptr->data == value ) {
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

bool LnList::remove(int value) {
	cNode *ptr = head,*pre = NULL;
	while( ptr != NULL ) {
		if( ptr->data == value ) {
			if( pre == NULL && ptr->next == NULL ) {
				delete head;
				head = new cNode;
				head = NULL;
			}
			else if( pre == NULL ) {
				head = ptr->next;
				delete ptr;
			}
			else if( ptr->next == NULL ) {
				pre->next = NULL;
				delete ptr;
			}
			else {
				pre->next = ptr->next;
				delete ptr;
			}
			return true;
		}
		pre = ptr;
		ptr = ptr->next;
	}
	return false;
}

void LnList::show() {
	cNode *ptr = head;
	if( head == NULL ) {
		cout << "LnList is empty now." << endl;
		return;
	}
	while( ptr != NULL ) {
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}
