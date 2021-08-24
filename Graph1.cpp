#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <windows.h>

#define VISITED 1
#define UNVISITED 0
#define CONNECTED 1
#define X 48 // 노드의 갯수

using namespace std;

vector<vector<int>> edge(X, vector<int>(X, 0)); // 2차원 벡터를 이용한 그래프 데이터 생성

vector<int> vertices;

void DFS(int vertex_idx) {
	vertices.at(vertex_idx) = VISITED;

	for(int i=0; i<edge.size(); i++) {
		if(edge.at(vertex_idx).at(i) == CONNECTED && vertices.at(i) == UNVISITED) {
			cout << i+1 << " ";
			DFS(i);
		}
	}
}

int main() {
	srand(GetTickCount());

	for (int i = 0; i < X; i++)
    	for (int j = 0; j < X; j++) {
			int serial = rand()%2;
        	edge[i][j] = serial;
		}
/*
	for (vector<int> vec : edge) {
    	for (int n : vec)
        printf("%3d ", n);
    cout << endl;
	}
	*/

	vertices.assign(edge.size(),UNVISITED);
	float sum;

	for(int i=0; i<edge.size(); i++) {
		int cnt = rand()%6;
		if(vertices.at(i) == UNVISITED) {
			cout << i+1 << " ";
			DFS(i);
		}
		sum += cnt;
	}
	cout << endl;
	cout << sum/5;
	return 0;
}