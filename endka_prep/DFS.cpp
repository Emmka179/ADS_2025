void dfs(int v, vector<vector<int>>& g, vector<int>& used) {
    used[v] = 1;
    for (int u : g[v])
        if (!used[u]) dfs(u, g, used);
}