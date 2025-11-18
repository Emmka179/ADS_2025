#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long long x1[200005], y1[200005], x2[200005], y2[200005];

    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    long long low = 1, high = 1000000000, ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        int count = 0;

        // считаем, сколько овец полностью помещаются в квадрат (0,0)-(mid,mid)
        for (int i = 0; i < n; i++) {
            if (x2[i] <= mid && y2[i] <= mid) {
                count++;
            }
        }

        if (count >= k) { 
            ans = mid;      // нашли длину, можно попробовать меньше
            high = mid - 1;
        } else {
            low = mid + 1;  // не хватает овец — увеличиваем квадрат
        }
    }

    cout << ans << endl;
    return 0;
}
