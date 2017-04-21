#include<iostream>
using namespace std;
const int V = 10;
void display(int gragh[V][V]) {
	int edges = 0;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (gragh[i][j] != 0) {
				if (gragh[i][j] == gragh[j][i]) {
					if (j >= i) {
						cout << i + 1 << '-' << j + 1 << ':' << ' ' << gragh[i][j] << endl;
						edges++;
					}
				}
				else {
					cout << i + 1 << '-' << '>' << j + 1 << ':' << ' ' << gragh[i][j] << endl;
					edges++;
				}
			}
		}
	}
	cout << "total edges: " << edges << endl;
}
int minKey(int key[], bool mstSet[]) {
	int min = INT_MAX;
	int min_index = 0;
	for (int v = 0; v < V; v++) {
		if (mstSet[v] == false && key[v] < min) {
			min = key[v];
			min_index = v;
		}
	}
	return min_index;
}
void primMST(int gragh[V][V]) {
	int parent[V];
	int key[V];
	bool mstSet[V];
	for (int i = 0; i < V; i++) {
		key[i] = INT_MAX;
		mstSet[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < V; count++) {
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < V; v++) {
			if (mstSet[v] == false && ((gragh[u][v] != 0 && gragh[u][v] < key[v]) || (gragh[v][u] != 0 && gragh[v][u] < key[v]))) {
				parent[v] = u;
				key[v] = gragh[u][v];
			}
		}
	}
	// cut the gragh to make MST
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			if (parent[i] != j && parent[j] != i) {
				gragh[i][j] = 0;
			}
		}
	}
}


int main() {
	int g1[V][V] = {
		{ 0, 2, 0, 6, 0, 2, 0, 3, 8, 5 },
		{ 2, 0, 3, 0, 0, 7, 0, 0, 0, 1 },
		{ 0, 3, 0, 0, 0, 0, 0, 7, 9, 0 },
		{ 6, 0, 0, 0, 4, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 4, 0, 0, 5, 0, 0, 0 },
		{ 2, 7, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 5, 0, 0, 0, 0, 8 },
		{ 3, 0, 7, 0, 0, 0, 0, 0, 0, 0 },
		{ 8, 0, 9, 0, 0, 0, 0, 0, 0, 3 },
		{ 5, 1, 0, 0, 0, 0, 8, 0, 3, 0 }
	};
	int g2[V][V] = {
		{ 0, 2, 0, 6, 0, 2, 0, 3, 8, 5 },
		{ 0, 0, 3, 0, 0, 7, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 7, 9, 0 },
		{ 0, 0, 0, 0, 4, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 5, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 8 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 2, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 3, 0, 0, 9, 0 }
	};
	cout << "print the undirected gragh" << endl;
	display(g1);
	cout << "print the MST of the undirected gragh using Prim's algorithm" << endl;
	primMST(g1);
	display(g1);
	cout << "print the directed gragh" << endl;
	display(g2);
	cout << "print the MST of the directed gragh using Prim's algorithm" << endl;
	primMST(g2);
	display(g2);

}
