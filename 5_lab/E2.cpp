#include <iostream>
using namespace std;

class Heap
{
private:
    long long *arr;
    long long heapSize;
    long long arrSize;

    long long left(long long i) { return 2 * i + 1; }
    long long right(long long i) { return 2 * i + 2; }
    long long parent(long long i) { return (i - 1) / 2; }

public:
    Heap(long long heapSize, long long arrSize)
    {
        this->heapSize = heapSize;
        this->arrSize = arrSize;
        this->arr = new long long[arrSize];
    }

    ~Heap() { delete[] arr; }

    void unHeapify(long long i)
    {
        if (i > 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            unHeapify(parent(i));
        }
    }

    void heapify(long long i)
    {
        long long smallest = i;
        long long l = left(i);
        long long r = right(i);

        if (l < heapSize && arr[l] < arr[smallest])
            smallest = l;
        if (r < heapSize && arr[r] < arr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    void insert(long long value)
    {
        if (heapSize < arrSize)
        {
            arr[heapSize] = value;
            unHeapify(heapSize);
            heapSize++;
        }
        else if (value > arr[0])
        {
            arr[0] = value;
            heapify(0);
        }
    }

    long long getSum()
    {
        long long sum = 0;
        for (long long i = 0; i < heapSize; i++)
            sum += arr[i];
        return sum;
    }
};

int main()
{
    long long q, k;
    cin >> q >> k;
    Heap h(0, k);

    for (int i = 0; i < q; i++)
    {
        string command;
        cin >> command;

        if (command == "print")
            cout << h.getSum() << endl;
        else
        {
            long long num;
            cin >> num;
            h.insert(num);
        }
    }

    return 0;
}
