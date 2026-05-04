#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];   // adjacency list stored row-wise
int deg[MAX];        // number of neighbors for each vertex
int visited[MAX];
int n;

// DFS function
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);

    for (int i = 0; i < deg[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    int s, x;

    scanf("%d", &n);

    // Read adjacency list
    for (int i = 0; i < n; i++) {
        deg[i] = 0;
        while (1) {
            scanf("%d", &x);
            if (x == -1) break;
            adj[i][deg[i]++] = x;
        }
    }

    scanf("%d", &s);

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Perform DFS
    dfs(s);

    return 0;
}