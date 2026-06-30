vector<int> bfs(int s, vector<vector<int>>& g) {
    vector<int> d(g.size(), -1);
    queue<int> q;
    q.push(s); d[s] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : g[v])
            if (d[u] < 0) d[u] = d[v] + 1, q.push(u);
    }
    return d;
}