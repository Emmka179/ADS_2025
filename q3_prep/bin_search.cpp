#include <iostream>
#include <vector>
using namespace std;

int binary_search_exact(vector<int>& a, int x) {
    int l = 0, r = (int)a.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;  // Avoids overflow
        if (a[mid] == x) return mid;
        if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1; // not found
}

int main() {
    vector<int> a = {3, 5, 8, 13, 18, 19, 21, 27, 32};
    int x = 13;
    int idx = binary_search_exact(a, x);
    cout << (idx != -1 ? "Found at index " + to_string(idx) : "Not found") << "\n";
    return 0;
}