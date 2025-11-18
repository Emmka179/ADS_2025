#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    bool erat[b + 1];
    for (int i = 0; i <= b; i++) erat[i] = true;

    erat[0] = erat[1] = false;

    for (int i = 2; i * i <= b; i++) {
        if (erat[i]) {
            for (int j = i * i; j <= b; j += i) {
                erat[j] = false;
            }
        }
    }

    for (int i = a; i <= b; i++) {
        if (erat[i]) cout << i << ' ';
    }

    return 0;
}