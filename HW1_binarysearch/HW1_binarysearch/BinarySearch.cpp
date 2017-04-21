#include<iostream>
using namespace std;
void selectsort(int A[], int len);
int binarysearch(int A[], int l, int h, int key);
void selectsort(int A[], int len) {
	int smallindex=0;
	int temp=0;
	for (int i = 0; i < len; i++) {
		smallindex = i;
		for (int j = i + 1; j < len; j++) {
			if (A[j] < A[smallindex]) {
				smallindex = j;
			}
		}
		if (smallindex != i) {
			temp = A[smallindex];
			A[smallindex] = A[i];
			A[i] = temp;
		}
	}
}
int binarysearch(int A[], int l, int h, int key) {
	int mid = (l + h) / 2;
	if (A[mid] == key) {
		cout << "The index of the value is:" << endl;
		return mid;
	}
	if (l >= h) {
		cout << "This array dose not contain the value." << endl;
		return -1;
	}
	else if (A[mid] > key) {
		h = mid - 1;
	}
	else {
		l = mid + 1;
	}
	binarysearch(A, l, h, key);
}
int main() {
	int val1;
	int val2;
	int A[15];
	for (int i = 0; i < 15; i++) {
		val1 = (rand() + 1) % 100;
		A[i] = val1;
	}
	selectsort(A, 15);
	cout << "The first array with 15 numbers:" << endl;
	for (int k = 0; k < 15; k++) {
		cout << A[k] << ' ';
	}
	cout << endl;
	cout << "Now let's implement the recursive binary search" << endl;
	cout << "Searching 35" << endl;
	cout << binarysearch(A, 0, 14, 35) << endl;
	cout << "Searching 22" << endl;
	cout << binarysearch(A, 0, 14, 22) << endl;
	cout << endl;
	int B[16];
	for (int i = 0; i < 16; i++) {
		val2 = (rand() + 1) % 100;
		B[i] = val2;
	}
	selectsort(B, 16);
	cout << "The second array with 16 numbers:" << endl;
	for (int m = 0; m < 16; m++) {
		cout << B[m] << ' ';
	}
	cout << endl;
	cout << "Now let's implement the recursive binary search" << endl;
	cout << "Searching 54" << endl;
	cout << binarysearch(B, 0, 16, 54) << endl;
	cout << "Searching 20" << endl;
	cout << binarysearch(B, 0, 16, 20) << endl;
	cout << endl;
}


