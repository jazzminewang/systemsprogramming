//graph.c
#include <stdio.h>

void printVertices(int N, int G[][N]) {
    for (int i = 0; i < N; i++) {
        printf("Vertex %d\n", i);
    }
}

void printEdges(int N, int G[][N]) {
    //rows
    printf("The graph has edges:\n");
    for (int i = 0; i < N; i++) {
        //columns
        for (int j = 0; j < N; j++) {
            if (G[i][j] == 1) {
                printf("[%d, %d]\n", i, j);
            }
        }
    }
}

void isThereAPath(int N, int G[][N], int v1, int v2) {
    //visited array to implement breadth-first search
    int visited[N];
    //queue implementation
    int front = 0;
    int rear = 0;
    int q[N];

    //make starting vertex as visited
    visited[v1] = 1;
    //enqueue starting vertex v
    q[rear] = v1; //insert at rear
    rear++; //increment rear

    while (rear != front) // condition
    {
        //dequeue
        int u = q[front];
        front++;

        //check
        if (u == v2) {
            printf("There is a path from Vertex %d to Vertex %d\n", v1, v2);
            return;
        }

        int i = 0;
        for (i = 0; i < N; i++) {
            //if there is adjacent vertex enqueue it
            if (!visited[i] && G[u][i]) {
                q[rear] = i;
                rear++;
                visited[i] = 1;
            }
        }
    }
    //failure to find path
    printf("There is no path from Vertex %d to Vertex %d\n", v1, v2);
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
