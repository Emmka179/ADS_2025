#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const long long pw = 31;

vector<long long> prefix_hash(string s) {
    int n = s.size();
    vector<long long> h(n + 5, 0), p(n + 5, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * pw + (s[i] - 'a' + 1)) % mod;
        p[i + 1] = (p[i] * pw) % mod;
    }
    return h;
}

long long get_hash(const vector<long long> &h, const vector<long long> &p, int l, int r) {
    long long res = (h[r] - h[l] * p[r - l]) % mod;
    if (res < 0) res += mod;
    return res;
}

long long n, h[55], power[55], a[55];
string ans;

void solve() {
    int n_input;
    cin >> n_input;
    n = n_input;

    power[0] = 1;
    for (int i = 1; i <= 51; i++) {
        power[i] = power[i - 1] * 2;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        long long cur;
        if (i > 0) 
            cur = (a[i] - a[i - 1]) / power[i] + 97;
        else 
            cur = a[i] + 97;
        cout << char(cur);
    }
    cout << endl;
}

int main() {
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}