#include <bits/stdc++.h>
using namespace std;

vector<int> rabin_karp_search(const string &text, const string &pattern) {
    const long long p = 31;
    const long long m = 1'000'000'007;

    int n = text.size();
    int k = pattern.size();

    if (k > n) return {};

    // Precompute powers of p
    vector<long long> p_pow(n + 1);
    p_pow[0] = 1;
    for (int i = 1; i <= n; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % m;
    }

    // Compute hash of pattern
    long long pattern_hash = 0;
    for (int i = 0; i < k; i++) {
        pattern_hash = (pattern_hash + (long long)pattern[i] * p_pow[i]) % m;
    }

    // Compute prefix hashes for text
    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] + (long long)text[i] * p_pow[i]) % m;
    }

    // Search for matches
    vector<int> result;
    for (int i = 0; i + k <= n; i++) {
        long long current_hash = (h[i + k] - h[i] + m) % m;

        // compare with pattern hash * p^i
        if (current_hash == (pattern_hash * p_pow[i]) % m) {
            // collision check
            if (text.substr(i, k) == pattern)
                result.push_back(i);
        }
    }

    return result;
}