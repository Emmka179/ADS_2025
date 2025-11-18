#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    cin >> m;
    int arr2[m];
    for (int i = 0; i < m; i++) cin >> arr2[i];


    int ans[n + m];
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr[i] < arr2[j]) {
            ans[k++] = arr[i++];
        } else {
            ans[k++] = arr2[j++];
        }
    }

    while (i < n) {
        ans[k++] = arr[i++];
    }

    // если остались элементы во втором массиве
    while (j < m) {
        ans[k++] = arr2[j++];
    }

    for (int t = 0; t < n + m; t++) cout << ans[t] << " ";
}
