#include<iostream>
#include<queue>
using namespace std;
class Gragh {
private:
	int M[10][16];
	bool visited[10];
public:
	Gragh(int m[10][16]);
	void DFS();
	void BFS();
	void DFS_util(int v);
	void BFS_util(int v);
};
Gragh::Gragh(int m[10][16]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 16; j++) {
			M[i][j] = m[i][j];
		}
	}
}
void Gragh::BFS() {
	cout << "do BFS traversal: ";
	for (int i = 0; i < 10; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < 10; i++) {
		if (visited[i] == false) {
			BFS_util(i);
		}
	}
	cout << endl;
}
void Gragh::DFS() {
	cout << "do DFS traversal: ";
	for (int i = 0; i < 10; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < 10; i++) {
		if (visited[i] == false) {
			DFS_util(i);
		}
	}
	cout << endl;
}
void Gragh::BFS_util(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	cout << v << " ";
	while (!q.empty()) {
		int node = q.front();
		for (int j = 0; j < 16; j++) {
			if (M[node][j] == 1) {
				for (int i = 0; i < 10; i++) {
					if ((M[i][j] == -1 || (M[i][j] == 1 && i != v)) && !visited[i]) {
						cout << i << " ";
						visited[i] = true;
						q.push(i);
					}
				}
			}
		}
		q.pop();
	}
}
void Gragh::DFS_util(int v) {
	visited[v] = true;
	cout << v << " ";
	for (int j = 0; j < 16; j++) {
		if (M[v][j] == 1) {
			for (int i = 0; i < 10; i++) {
				if ((M[i][j] == -1 || (M[i][j]== 1 && i!=v)) && !visited[i]) {
					DFS_util(i);
				}
			}
		}
	}
}
int main() {
	int m1[10][16] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, -1, 0, 1, 0, 0 },
		{ -1, -1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0,-1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, -1, 1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, -1, 0, -1, 0, -1, 1, -1, -1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1, -1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, -1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1 }
	};
	int m2[10][16] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0 },
		{ 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
	};
	int m3[10][16] = {
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
	};
	Gragh g1 = Gragh(m1);
	Gragh g2 = Gragh(m2);
	Gragh g3 = Gragh(m3);
	cout << "traverse directed gragh: " << endl;
	g1.DFS();
	g1.BFS();
	cout << "traverse undirected connected gragh: " << endl;
	g2.DFS();
	g2.BFS();
	cout << "traverse undirected disconnected gragh: " << endl;
	g3.DFS();
	g3.BFS();
}