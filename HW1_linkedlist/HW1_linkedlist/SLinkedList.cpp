#include <iostream>
using namespace std;
class Node {
private:
	int number;
	Node* next;
	friend class LinkedList;
};
class LinkedList {
private:
	Node* head;
public:
	LinkedList();
	~LinkedList();
	void add(int num);
	void traverse();
	void selectionsort();
	void swap(Node* f, Node* s);
};
LinkedList::LinkedList() {
	head = NULL;
}
LinkedList::~LinkedList() {}
void LinkedList::add(int num) {
	Node* v = new Node;
	v->number = num;
	v->next = head;
	head = v;
}
void LinkedList::traverse() {
	Node* start;
	start = head;
	if (start == NULL) {
		cout << "empty linkedlist" << endl;
	}
	while (start != NULL) {
		cout << start->number << ' ';
		start = start->next;
	}
	cout << endl;
}
void LinkedList::selectionsort() {
	Node* current;
	Node* current2;
	Node* min;
	Node* iterator;
	iterator = head;
	while (iterator != NULL) {
		current = iterator;
		min = current;
		current2 = current->next;
		while (current2 != NULL) {
			if (min->number > current2->number) {
				min = current2;
			}
			current2 = current2->next;
		}
		swap(current, min);
		iterator = min->next;
	}
}
void LinkedList::swap(Node* f, Node* s) {
	Node* prev1 = head;
	Node* prev2 = head;
	Node* temp;
	if (f != head&&s != head) {
		while (prev1->next != f) {
			prev1 = prev1->next;
		}
		while (prev2->next != s) {
			prev2 = prev2->next;
		}
		prev1->next = s;
		prev2->next = f;
		temp = s->next;
		s->next = f->next;
		f->next = temp;
	}
	else if (f == head&&s != head) {
		while (prev2->next != s) {
			prev2 = prev2->next;
		}
		prev2->next = f;
		temp = s->next;
		s->next = f->next;
		f->next = temp;
		head = s;
	}
}
int main() {
	int val;
	int size = 10;
	LinkedList list;
	for (int i = 0; i < size; i++) {
		val = (rand() + 1) % 100;
		list.add(val);
	}
	list.traverse();
	cout << "Now let's implement the selection sort" << endl;
	list.selectionsort();
	list.traverse();
}
