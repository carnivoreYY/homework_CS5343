#include<iostream>
using namespace std;
const int n = 20;
void display(int a[]) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
void LSD(int a[]) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	for (int e = 1; max / e > 0; e *= 10) {
		int output[n];
		int count[10] = { 0 };
		for (int i = 0; i < n; i++) {
			count[(a[i] / e) % 10]++;
		}
		for (int i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		for (int i = n - 1; i >= 0; i--) {
			output[count[(a[i] / e) % 10] - 1] = a[i];
			count[(a[i] / e) % 10]--;
		}
		for (int i = 0; i < n; i++) {
			a[i] = output[i];
		}
	}
}
int main() {
	int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = 0;
		for (int j = 0; j < 6; j++) {
			a[i] *= 10;
			a[i] += rand() % 10;
		}
	}
	cout << "print out the numbers before sorting" << endl;
	display(a);
	LSD(a);
	cout << "print out the numbers after sorting" << endl;
	display(a);
}