#include<iostream>
using namespace std;
void show(int* A, int len);
void Max_heap(int* A, int j, int len);
void heapify(int* A, int len);
void heapsort(int* A, int len);
void Max_heap(int* A, int j, int len) {
	int left = 2 * j;
	int right = 2 * j + 1;
	if (left > len || right > len) {
		return;
	}
	int temp, max;
	if (A[left] > A[j]) {
		max = left;
	}
	else {
		max = j;
	}
	if (A[right] > A[max]) {
		max = right;
	}
	if (j != max) {
		temp = A[j];
		A[j] = A[max];
		A[max] = temp;
		Max_heap(A, max, len);
	}
}
void heapify(int* A, int len) {
	for (int k = len / 2; k >= 1; k--) {
		Max_heap(A, k, len);
	}
}
void heapsort(int* A, int len) {
	int temp;
	for (int i = len; i >= 2; i--) {
		temp = A[i];
		A[i] = A[1];
		A[1] = temp;
		Max_heap(A, 1, i - 1);
	}
}
void show(int* A, int len) {
	for (int i = 1; i <= len; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
}
int main() {
	int a[16];
	int val;
	a[0] = 15; //store the number of this array in the first element
	for (int i = 1; i <= 15; i++) {
		val = (rand() + 1) % 100;
		a[i] = val;
	}
	cout << "before heapify the array" << endl;
	show(a, 15);
	heapify(a, 15);
	cout << "after heapify and before sort the array" << endl;
	show(a, 15);
	heapsort(a, 15);
	cout << "after sort the array" << endl;
	show(a, 15);
}