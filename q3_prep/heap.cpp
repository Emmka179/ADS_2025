void heapify(int a[], int n, int i) {
    int largest = i;
    int l = 2*i, r = 2*i + 1;

    if (l <= n && a[l] > a[largest]) largest = l;
    if (r <= n && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n/2; i >= 1; i--)
        heapify(a, n, i);

    for (int i = n; i > 1; i--) {
        swap(a[1], a[i]);
        heapify(a, i-1, 1);
    }
}
