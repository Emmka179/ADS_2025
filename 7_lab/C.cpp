#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int arr[n];
    int brr[m];

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < m; i++) cin >> brr[i];

    int a = 0, b = 0;

    while (a < n && b < m) {
        if (arr[a] == brr[b]) {
            cout << arr[a] << " ";
            a++;
        }
        else cout << brr[b] << " "; b++;
    }
}