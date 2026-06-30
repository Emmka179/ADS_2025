#include <bits/stdc++.h>
using namespace std;

vector<int> prim(const vector<vector<pair<int,int>>> &graph, int start) {
    int n = graph.size();
    vector<int> parent(n, -1), key(n, INT_MAX);
    vector<bool> visited(n, false);
    key[start] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, start});

    while (!q.empty()) {
        auto [w, u] = q.top();
        q.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (auto [v, weight] : graph[u]) {
            if (!visited[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                q.push({key[v], v});
            }
        }
    }
    return parent;
}