#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int deg[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

// DFS function
void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < deg[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            dfs(u);
        }
    }

    // push after visiting all neighbors
    stack[++top] = v;
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

    // Run DFS for all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // Print topological order
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}