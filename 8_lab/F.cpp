#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll pw1 = 31;
const ll pw2 = 37;
const int N = 2005;

ll h1[N], h2[N], p1[N], p2[N];

pair<ll,ll> get_hash(int l, int r) {
    ll x = (h1[r] - h1[l] * p1[r - l]) % mod1;
    if (x < 0) x += mod1;
    ll y = (h2[r] - h2[l] * p2[r - l]) % mod2;
    if (y < 0) y += mod2;
    return {x, y};
}

int main() {
    string s;
    cin >> s;
    int n = s.size();

    p1[0] = p2[0] = 1;
    for(int i = 1; i <= n; i++){
        p1[i] = (p1[i-1] * pw1) % mod1;
        p2[i] = (p2[i-1] * pw2) % mod2;
    }

    for(int i = 0; i < n; i++){
        h1[i+1] = (h1[i] * pw1 + (s[i]-'a'+1)) % mod1;
        h2[i+1] = (h2[i] * pw2 + (s[i]-'a'+1)) % mod2;
    }

    unordered_set<uint64_t> st;
    for(int len = 1; len <= n; len++){
        for(int i = 0; i + len <= n; i++){
            auto pr = get_hash(i, i+len);
            uint64_t combined = ((uint64_t)pr.first << 32) | (uint64_t)pr.second;
            st.insert(combined);
        }
    }

    cout << st.size() << "\n";
    return 0;
}