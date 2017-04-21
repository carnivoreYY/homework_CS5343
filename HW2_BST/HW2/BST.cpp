#include<iostream>
#include<stdlib.h> 
using namespace std;
class Node {
private:
	int number;
	Node* left;
	Node* right;
	friend class BST;
};
class BST {
private:
	Node* root;
public:
	BST();
	~BST();
	void insert(int v);
	void display();
	void remove(int v);
	Node* add(Node* r, int v);
	void traverse(Node* r);
	Node* remove(Node* r, int v);
	Node* Min(Node* r);
};
BST::BST() {
	root = NULL;
}
BST::~BST() {}
void BST::insert(int v) {
	root = add(root, v);
}
void BST::display() {
	traverse(root);
	cout << endl;
}
void BST::remove(int v) {
	root = remove(root, v);
}
Node* BST::add(Node* r, int v) {
	if (r == NULL) {
		Node* n = new Node;
		n->number = v;
		n->left = NULL;
		n->right = NULL;
		return n;
	}
	else if (r->number > v) {
		r->left = add(r->left, v);
	}
	else {
		r->right = add(r->right, v);
	}
	return r;
}
void BST::traverse(Node* r) {
	if (r == NULL) {
		return;
	}
	traverse(r->left);
	cout << r->number << ' ';
	traverse(r->right);
}
Node* BST::remove(Node* r, int v) {
	Node* temp = new Node;
	if (r == NULL) {
		return NULL;
	}
	else if (r->number > v) {
		r->left = remove(r->left, v);
	}
	else if (r->number < v) {
		r->right = remove(r->right, v);
	}
	else if (r->left != NULL&&r->right != NULL) {
		temp = Min(r->right);
		r->number = temp->number;
		r->right = remove(r->right, r->number);
	}
	else {
		if (r->left == NULL) {
			r = r->right;
		}
		else if (r->right == NULL) {
			r = r->left;
		}
	}
	return r;
}
Node* BST::Min(Node* r) {
	if (r == NULL) {
		return NULL;
	}
	if (r->left == NULL) {
		return r;
	}
	else {
		r = Min(r->left);
	}
	return r;
}
int main() {
	BST b;
	int val;
	for (int i = 0; i < 15; i++) {
		val = (rand() + 1) % 100;
		b.insert(val);
	}
	cout << "Display the tree before deletion with in-order traverse" << endl;
	b.display();
	cout << "Delete a leaf node in the tree and display it" << endl;
	b.remove(82);
	b.display();
	cout << "Delete a non-leaf node with leaf predecessor or successor and display it" << endl;
	b.remove(63);
	b.display();
	cout << "Delete a non-leaf node with non-leaf predecessor or successor and display it" << endl;
	b.remove(28);
	b.display();
	return 0;
}