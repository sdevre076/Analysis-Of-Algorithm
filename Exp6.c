#include <stdio.h>

#define MAX 10
#define INF 99999   // assume large number as infinity

void floydWarshall(int n, int graph[MAX][MAX]) {
    int dist[MAX][MAX];

    // Step 1: Initialize distance matrix as graph matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Step 2: Floyd-Warshall main loop
    for (int k = 0; k < n; k++) {           // intermediate vertex
        for (int i = 0; i < n; i++) {       // source
            for (int j = 0; j < n; j++) {   // destination
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Step 3: Print shortest distance matrix
    printf("\nAll-Pairs Shortest Path Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int graph[MAX][MAX];

    printf("Enter number of vertices (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter adjacency matrix (use %d for INF where no edge):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    floydWarshall(n, graph);

    return 0;
}
