#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, P;
    if (!(cin >> N >> M >> P)) return 0;

    struct Item { ll gain; int c, d; };
    vector<Item> a(N);
    vector<vector<ll>> add(P + 2), rem(P + 2);

    ll baseline = 0;
    for (int i = 0; i < N; ++i) {
        ll ai, bi;
        int ci, di;
        cin >> ai >> bi >> ci >> di;
        a[i].gain = ai - bi;
        a[i].c = ci;
        a[i].d = di;
        baseline += bi * 1LL * (di - ci);
        if (a[i].gain > 0) {
            add[ci].push_back(a[i].gain);
            rem[di].push_back(a[i].gain);
        }
    }

    multiset<ll> top;  
    multiset<ll> rest;  
    ll sumTop = 0;      
    ll total_extra = 0; 

    for (int stop = 1; stop <= P; ++stop) {
        for (ll g : rem[stop]) {
            auto it = rest.find(g);
            if (it != rest.end()) {
                rest.erase(it);
            } else {
                it = top.find(g);
                if (it != top.end()) {
                    sumTop -= g;
                    top.erase(it);
                    if ((int)top.size() < M && !rest.empty()) {
                        auto it2 = prev(rest.end());
                        ll val = *it2;
                        rest.erase(it2);
                        top.insert(val);
                        sumTop += val;
                    }
                }
            }
        }

        for (ll g : add[stop]) {
            if (M > 0 && (int)top.size() < M) {
                top.insert(g);
                sumTop += g;
            } else {
                if (M > 0 && !top.empty()) {
                    auto itmin = top.begin();
                    if (g > *itmin) {
                        ll small = *itmin;
                        top.erase(itmin);
                        sumTop -= small;
                        rest.insert(small);

                        top.insert(g);
                        sumTop += g;
                    } else {
                        rest.insert(g);
                    }
                } else {
                    rest.insert(g);
                }
            }
        }

        if (stop < P) {
            total_extra += sumTop; 
        }
    }

    ll answer = baseline + total_extra;
    cout << answer << "\n";
    return 0;
}