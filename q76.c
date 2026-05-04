#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int deg[MAX];
int visited[MAX];
int n, m;

// DFS
void dfs(int v) {
    visited[v] = 1;

    for (int i = 0; i < deg[v]; i++) {
        int u = adj[v][i];
        if (!visited[u]) {
            dfs(u);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);

    int u, v;

    // initialize
    for (int i = 1; i <= n; i++) {
        deg[i] = 0;
        visited[i] = 0;
    }

    // read edges (undirected)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][deg[u]++] = v;
        adj[v][deg[v]++] = u;
    }

    int count = 0;

    // check all nodes
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    printf("%d", count);

    return 0;
}