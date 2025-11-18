#include <iostream>
using namespace std;

class Heap {
private:
    long long *arr;
    long long heapSize;
    long long arrSize;

     // helper:
    long long left(long long i)
    {
        return 2 * i + 1;
    }
    long long right(long long i)
    {
        return 2 * i + 2;
    }
    long long parent(long long i)
    {
        return (i - 1) / 2;
    }

public:
    Heap(long long heapSize = 0) {
        this->heapSize = heapSize;
        this->arrSize = 1000000;
        arr = new long long[arrSize];
    }
    ~Heap() { delete[] arr; }

    void heapify(long long i) {
        long long largest_index = i;
        if (left(i) < heapSize && arr[left(i)] > arr[largest_index])
            largest_index = left(i);
        if (right(i) < heapSize && arr[right(i)] > arr[largest_index])
            largest_index = right(i);
        if (largest_index != i) {
            swap(arr[largest_index], arr[i]);
            heapify(largest_index);
        }
    }

    void buildHeap(long long *input, long long n) {
        heapSize = n;
        for (long long i = 0; i < n; i++)
            arr[i] = input[i];
        for (long long i = (heapSize / 2) - 1; i >= 0; i--)
            heapify(i);
    }

    void unheapify(long long i) {
        while (i > 0 && arr[parent(i)] < arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    void insertInHeap(long long newVal) {
        arr[heapSize] = newVal;
        heapSize++;
        unheapify(heapSize - 1);
    }

    long long deleteRoot() {
        if (heapSize == 0)
            return 0;
        long long ans = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;
        if (heapSize > 0)
            heapify(0);
        return ans;
    }

    long long absVal(long long n) {
        return n < 0 ? -n : n;
    }

    long long getSize() { return heapSize; }
};

int main() {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++)
        cin >> arr[i];

    Heap h;
    h.buildHeap(arr, n);

    long long ans = 0;
    while (h.getSize() > 0) {
        if (h.getSize() == 1)
            ans = h.deleteRoot();
        else {
            long long first = h.deleteRoot();
            long long second = h.deleteRoot();
            if (first != second)
                h.insertInHeap(h.absVal(first - second));
        }
    }

    cout << ans;
    return 0;
}
