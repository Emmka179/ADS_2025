#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(const vector<vector<pair<int,int>>> &graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, start});

    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (d > dist[u]) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    return dist;
}
