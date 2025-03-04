#include <stdio.h>
#define INF 99999
#define V 4

void floydWarshall(int graph[][V], int dist[][V], int pred[][V]) {
    int i, j, k;
    
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
            if(i != j && graph[i][j] != INF)
                pred[i][j] = i;
            else
                pred[i][j] = -1;
        }
}
    
    for(k = 0; k < V; k++) {
        for(i = 0; i < V; i++) {
            for(j = 0; j < V; j++) {
                if(dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = pred[k][j];
                }
            }
        }
    }
}

void printPath(int pred[][V], int i, int j) {
    if(pred[i][j] == -1) {
        //printf("No path  ");
        return;
    }
    if(i != j) {
        printPath(pred, i, pred[i][j]);
    }
    printf("%d ", j);
}

int main() {
    int graph[V][V] = { {0, 8, INF, 1},
                        {INF, 0, 1, INF},
                        {4, INF, 0, INF},
                        {INF, 2, 9, 0} };
    int dist[V][V], pred[V][V], i, j;

    floydWarshall(graph, dist, pred);

    printf("Shortest distances between every pair of vertices:\n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            if(dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    printf("\nShortest paths between pairs of vertices:\n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            if(i != j) {
                printf("Path from %d to %d: ", i, j);
                printPath(pred, i, j);
                printf("\n");
            }
        }
    }
    
    return 0;
}

