#include"List.hpp"

void List::expand() {
	float *temp = new float[capacity];
	for(int i=0; i<capacity; ++i) {
		temp[i] = dynamic_array[i];
	}
	capacity *= 2;
	for(int i=capacity/2; i<capacity; ++i) {
		temp[i] = -1;
	}
	delete dynamic_array;
	dynamic_array = temp;
	temp = NULL;
}

List::List() {
	dynamic_array = new float[1];
	*dynamic_array = -1;
	size = 0;
	capacity = 1;
}

List::List(float x) {
	dynamic_array = new float[1];
	*dynamic_array = x;
	size = 1;
	capacity = 1;
}

List::~List() {
	delete dynamic_array;
	cout << "List has been deleted!" << endl;
}

void List::insert_at(int index, float x) {
	while( index >= capacity ) {
		expand();
	}
	dynamic_array[index-1] = x;
	++size;
	cout << "insert sucess." << endl;
}

void List::remove_at(int index) {
	if( index >= capacity || size == 0 ) {
		cout << "The index is empty." << endl;
		return;
	}
	else {
		dynamic_array[index-1] = -1;
	}
	--size;
	cout << "remove sucess." << endl;
}

void List::value_show() {
	if( size == 0 ) {
		cout << "List is empty now." << endl;
		return;
	}
	for(int i=0; i<capacity; ++i) {
		if( dynamic_array[i] != -1 ) {
			cout << dynamic_array[i];
		}
	}
	cout << endl;
}

bool List::find(int index) {
	if( index >= size ) return false;
	return true;
}

float List::value_at(int index) {
	return dynamic_array[index];
}
