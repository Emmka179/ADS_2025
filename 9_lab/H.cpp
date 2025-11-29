#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    int count = 0;

    for (int len = 1; 2 * len < n; len++) {
        int i = 0;
        for (; i < len; i++) {
            if (s[i] != s[i + len])
                break;
        }
        if (i == len) count++;
    }

    cout << count;
    return 0;
}
