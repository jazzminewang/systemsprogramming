//graph.c
#include <stdio.h>

void printVertices(int N, int G[][N]) {

}

void printEdges(int N, int G[][N]) {

}

void isThereAPath(int N, int G[][N], int v1, int v2) {

}

#define N 5

int main() {

	int Graph[N][N] = { 	{0,1,0,0,1},
				{1,0,0,0,1},
				{0,0,0,1,0},
				{0,0,1,0,0},
				{1,1,0,0,0}
			};

	printVertices(N, Graph);
	printEdges(N, Graph);
	isThereAPath(N, Graph, 0, 1);
	isThereAPath(N, Graph, 0, 3);

	return 0;

}
