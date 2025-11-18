#include <bits/stdc++.h>
using namespace std;

int main() {
    int b;
    cin >> b;                          // количество элементов в arr1
    int arr1[b];
    for (int i = 0; i < b; i++) cin >> arr1[i];

    int n, m;
    cin >> n >> m;                     // размеры матрицы
    int arr2[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr2[i][j];
        }
    }

    // Для каждого элемента из arr1 проверяем наличие в arr2
    for (int k = 0; k < b; k++) {
        int target = arr1[k];
        bool found = false;

        for (int i = 0; i < n; i++) {
            // обязательно — каждая строка должна быть отсортирована!
            if (binary_search(arr2[i], arr2[i] + m, target)) {
                int pos = lower_bound(arr2[i], arr2[i] + m, target) - arr2[i];
                cout << "Found " << target << " at row " << i << ", column " << pos << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << -1 << endl;
        }
    }

    return 0;
}
