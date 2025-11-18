#include <iostream>
#include <limits.h>
#include <cmath>
#include <ctime>
using namespace std;

void print(int* arr, int n){
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int partition(int* arr, int beg, int end){
    srand(time(0));
    int pivot = beg + (rand() % (end - beg + 1));
    swap(arr[pivot], arr[end]);
    int i = beg - 1;
    for (int j = beg; j < end; j++){
        if (arr[j] < arr[end]){
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[end]);
    return i + 1;
}

void quickSort(int* arr, int beg, int end){  
    if (beg < end){
        int part = partition(arr, beg, end);
        quickSort(arr, beg, part - 1);
        quickSort(arr, part + 1, end); 
    }
}

void merge(int* arr, int beg, int mid, int end){
    int* left = new int[mid - beg + 2];
    int* right = new int[end - mid + 1];

    for (int i = beg; i <= mid; i++)
        left[i - beg] = arr[i];
    for (int i = mid + 1; i <= end; i++)
        right[i - (mid + 1)] = arr[i];

    left[mid - beg + 1] = INT_MAX;
    right[end - mid] = INT_MAX;

    int i = 0, j = 0;
    for (int k = beg; k <= end; k++){
        if (left[i] < right[j]) arr[k] = left[i++];
        else arr[k] = right[j++];
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int* arr, int beg, int end){
    if (beg < end){
        int mid = (beg + end) / 2;
        mergeSort(arr, beg, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, beg, mid, end);
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    int* a = new int[n];
    int* b = new int[m];

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    mergeSort(a, 0, n - 1);
    mergeSort(b, 0, m - 1);

    int i = 0, j = 0;
    while (i < n && j < m){
        if (a[i] == b[j]){
            cout << a[i] << " ";
            i++;
            j++;
        }
        else if (a[i] < b[j]) i++;
        else j++;
    }
}