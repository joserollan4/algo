// given a tree G, 
// determine the number of pairs of nodes (u, v)
// such that distance of u to v = k

int n, k;
vector<vector<int>> adj(50003);
ll d[50003][503];

ll ans = 0;

void dfs(int u, int p) {
    d[u][0] = 1;
    for (auto &v:adj[u]) {
        if (v != p) {
            dfs(v, u);
            for (int j=1; j<=k; j++) {
                ans += (d[v][j - 1] * d[u][k - j]); 
            }
            for (int j=1; j<=k; j++) {
                d[u][j] += (d[v][j - 1]);
            }
        }
    }
}

void run() {
  dfs(1, 0);
}
