//graph.c
#include <stdio.h>

void printVertices(int N, int G[][N]) {
    for (int i = 0; i < N; i++) {
        printf("Vertex %d", i);
    }
}

void printEdges(int N, int G[][N]) {
    //rows
    printf("The graph has edges: ");
    for (int i = 0; i < N; i++) {
        //columns
        for (int j = 0; j < N; j++) {
            if (G[i][j] == 1) {
                printf("[%d, %d]", i, j);
            }
        }
    }
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

// The graph has vertices: Vertex 0
// Vertex 1
// Vertex 2
// Vertex 3
// Vertex 4
// The graph has edges: [0, 1]
// [0, 4]
// [1, 0]
// [1, 4]
// [2, 3]
// [3, 2]
// [4, 0]
// [4, 1]
// Yes, there is a path between Vertex 0 and Vertex 1.
// No, there is no path between Vertex 0 and Vertex 3.
