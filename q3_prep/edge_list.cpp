#include <bits/stdc++.h>
using namespace std;



struct Edge{ int u, v, w; };

vector<Edge> g;     // список рёбер

int main(){

g.push_back({u, v, w});   // добавить ребро, w - вес

int n, m; 
cin >> n >> m;
vector<Edge> g(m);

for(int i=0;i<m;i++)
    cin >> g[i].u >> g[i].v >> g[i].w;

}