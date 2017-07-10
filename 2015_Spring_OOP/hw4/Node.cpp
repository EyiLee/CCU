#include"Node.hpp"

void Node::recursive(Node *ptr) {
	if( ptr->left != NULL ) {
		recursive(ptr->left);
		delete ptr->left;
	}
	if( ptr->right != NULL ) {
		recursive(ptr->right);
		delete ptr->right;
	}
}

void Node::show(Node *ptr) {
	if( ptr->left != NULL ) {
		show(ptr->left);
	}
	cout << ptr->data << " ";
	if( ptr->right != NULL ) {
		show(ptr->right);
	}
}

Node::Node() {
	left = NULL;
	right = NULL;
}

Node::Node(int x) {
	data = x;
	left = NULL;
	right = NULL;
}

Node::~Node() {
	recursive(left);
	delete left;
	recursive(right);
	delete right;
}

void Node::insert(int value, int index) {
	Node *ptr = this;
	int que[32];
	if( index <= 1 ) {
		ptr->data = value;
		return;
	}
	int i = 0;
	while( index != 0 ) {
		que[i] = index & 1;
		index /= 2;
		++i;
	}
	i -= 2;
	for(; i>0; --i) {
		if( que[i] == 1 ) {
			ptr = ptr->right;
		}
		else {
			ptr = ptr->left;
		}
	}
	if( que[0] == 1 ) {
		ptr->right = new Node(value);
	}
	else {
		ptr->left = new Node(value);
	}
}

void Node::display() {
	show(this);
	cout << endl;
}

bool same_tree(Node *l,Node *r) {
	if( l == NULL && r == NULL ) {
		return true;
	}
	else if( l == NULL || r == NULL ) {
		return false;
	}
	if( l->data == r->data ) {
		return (same_tree(l->left,r->left) && same_tree(l->right,r->right));
	}
	return false;
}
