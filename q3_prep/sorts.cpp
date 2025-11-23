#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void bubbleSort(vector<int> *arr){
    bool swap;
    int n = arr.size();

    for(int i = 0; i < n-1; i++){
        swap = false;
        for(int j = 0; j < n - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                swap(a[j], a[j+1]);
                swap = true;
            }
        }
        if(!swap) break;
    }
}

void insertionSort(vector<int> *b){
    int n = b.size();
    for(int i = 0; i < n; i++){
        int key = b[i];
        int j = i - 1;
        while(j>=0 && b[j] > key){
            b[j + 1] = b[j];
            j--;
        }
        b[j + 1] = key;
    }
}


void mergeSort(vector<int> &d, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);

    for(int i = 0; i < n1; i++){
        leftArr[i] = d[left + i];
    }
    for(int j = 0; j < n2; j++){
        rightArr[j] = d[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2){
        if(leftArr[i] < rightArr[j]){
            d[k++] = leftArr[i++];
        }
        else{
            d[k++] = rightArr[j++];
        }
    }

    while(i < n1){
        d[k++] = leftArr[i++];
    }
    while(j < n2){
        d[k++] = rightArr[j++];
    }
}



void partititionArr(vector<int> &c, int low, int high){
    int pivot = c[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(c[j] < pivot){
            i++;
            swap(c[i], c[j]);
        }
    }
    swap(c[i + 1], c[high]);
    return i + 1;
}

void quickSort(vector<int> *c){
    if(low < high){
        int pi = partitionArr(c, low, high);
        quickSort(c, low, pi-1);
        quickSort(c, pi+1, high);
    }
}


int main(){
    vector<int> a = {5, 2, 9, 1, 5, 6};

    bubbleSort(a); //bubble
    
    insertionSort(a); //insertion

    mergeSort(a, 0, (int)a.size() - 1); //merge

    quickSort(a, 0, (int)a.size() - 1); //quick

    for (int x : a) 
        cout << x << " ";
    
    return 0;

}