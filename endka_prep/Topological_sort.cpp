void dfs(const vector<vector<int>> &graph, int v, vector<int> &visited, vector<int> &order) {
    visited[v] = 1;
    for (int to : graph[v])
        if (!visited[to])
            dfs(graph, to, visited, order);
    order.push_back(v);
}

vector<int> topological_sort(const vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> visited(n, 0), order;
    for (int v = 0; v < n; v++)
        if (!visited[v])
            dfs(graph, v, visited, order);
    reverse(order.begin(), order.end());
    return order;
}



void dfs(int v, vector<vector<int>>& g, vector<int>& used) {
    used[v] = 1;
    for (int u : g[v])
        if (!used[u]) 
            dfs(u, g, used);
}