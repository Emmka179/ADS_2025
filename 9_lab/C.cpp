#include <iostream>
#include <string>
#include <vector>
using namespace std;

void buildLPS(string &p, vector<int> &lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < p.length()) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0)
                len = lps[len - 1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string &pat, string &txt) {
    int n = txt.length(), m = pat.length();
    vector<int> lps(m), res;
    buildLPS(pat, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;
            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        } else {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;

    if (a.size() != b.size()) {
        cout << -1;
        return 0;
    }

    string doubled = a + a;
    vector<int> positions = search(b, doubled);

    if (positions.empty()) {
        cout << -1;
    } else {
        int pos = positions[0];
        int n = a.size();
        int shift = (n - pos) % n;
        cout << shift;
    }

    return 0;
}