#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n,0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

struct Edge { int u, v, w; };

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

vector<Edge> kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), cmp);
    DSU dsu(n);
    vector<Edge> mst;
    for (int i = 0; i < edges.size(); i++)
        if (dsu.unite(edges[i].u, edges[i].v))
            mst.push_back(edges[i]);
    return mst;
}


// kruskal
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

bool creates_cycle(int u, int parent, const vector<vector<int>> &g, vector<int> &visited) {
    visited[u] = 1;
    for (int to : g[u])
        if (!visited[to]) {
            if (creates_cycle(to, u, g, visited))
                return true;
        } else if (to != parent)
            return true;
    return false;
}

vector<Edge> kruskal(int n, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), cmp);
    vector<vector<int>> g(n);
    vector<Edge> mst;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].u, v = edges[i].v;
        g[u].push_back(v);
        g[v].push_back(u);
        vector<int> visited(n, 0);
        if (!creates_cycle(u, -1, g, visited))
            mst.push_back(edges[i]);
        else {
            g[u].pop_back();
            g[v].pop_back();
        }
    }
    return mst;
}
