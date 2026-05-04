#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int deg[MAX];
int visited[MAX];
int n;

// DFS to detect cycle
int dfs(int v, int parent) {
    visited[v] = 1;

    for (int i = 0; i < deg[v]; i++) {
        int u = adj[v][i];

        if (!visited[u]) {
            if (dfs(u, v))
                return 1;
        }
        else if (u != parent) {
            return 1; // cycle found
        }
    }
    return 0;
}

int main() {
    int x;

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

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES");
                return 0;
            }
        }
    }

    printf("NO");
    return 0;
}