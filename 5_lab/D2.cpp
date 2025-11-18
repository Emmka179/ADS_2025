#include <iostream>
#include <climits>
using namespace std;

class Heap
{
private:
    
public:
    int* arr;
    int heapSize;
    int arrSize;


    //helper funcs:
    int left(int i){
        return 2*i+1;
    }
    int right(int i){
        return 2*i+2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    Heap(int* newArr, int arrSize){
        this->arrSize = arrSize;
        arr = new int[arrSize];//warning -- DMA
        heapSize = arrSize;
        for (int i = 0; i < arrSize; i++)
        {
            arr[i] = newArr[i];
        }
    }
    ~Heap(){
        delete[] arr;
    }


    void printArray(){
        for (int i = 0; i < arrSize; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void heapify(int i){
        int largest_index = i;
        if (left(i) < heapSize && arr[left(i)] > arr[largest_index]) {
            largest_index = left(i);
        }
        if (right(i) < heapSize && arr[right(i)] > arr[largest_index]) {
            largest_index = right(i);
        }

        swap(arr[largest_index],arr[i]);
        if(largest_index!=i){      //if swapped
            heapify(largest_index);
        }
    }

    void buildHeap(){
        for (int i = (heapSize-2)/2; i>=0; i--)
        {
            heapify(i);
        }
    }

    void heapSortMax(){
        buildHeap();      //max -- arr[0]
        while(heapSize>0){
            swap(arr[0],arr[heapSize-1]);
            heapSize--;
            heapify(0);
        }
    }

    void heapSortMin(){
        buildHeap();      //max -- arr[0]
        while(heapSize>0){
            swap(arr[heapSize-1],arr[0]);
            heapSize--;
            heapify(0);
        }
    }

    void printHeap(){
        for (int i = 0; i < heapSize; i++)
        {
            cout<<arr[i]<<" ";
        }
    }

    void unheapify(int i){
        if(parent(i)>=0 && arr[parent(i)]<arr[i]){
            swap(arr[parent(i)],arr[i]);
            unheapify(parent(i));
        }
    }

    void changeVal(int changedVal, int i){
        arr[i] = changedVal;
        unheapify(i);
    }

    void insertInHeap(int newVal){
        heapSize++;
        arr[heapSize-1] = newVal;
        unheapify(heapSize-1);
    }

    void deleteInHeap(int i){
        arr[i] = INT_MIN;
        swap(arr[0],arr[heapSize-1]);
        heapify(0);
        heapSize--;
    }

    void deleteRoot(){
        swap(arr[0], arr[heapSize - 1]);
        heapSize--;
        heapify(0);
    }
};


int main(){
    int n, k; cin >> n; cin >> k;
    int sum=0;
    int arr[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    Heap h1(arr, n);

    h1.heapSortMin();

    while(h1.heapSize > 0){
        int first = h1.arr[0];
        h1.deleteRoot();
        int second = h1.arr[0];
        h1.deleteRoot();

        int d_new = first + 2*second;

        if(d_new < k){
            h1.insertInHeap(d_new);
            sum++;

            if(h1.heapSize == 0 && d_new < k){
                cout << -1;
                return 0;
            }

        } 
        else{
            sum++;
            cout << sum;
        }
    }
    if(h1.heapSize == 0) cout << sum;
    else if(h1.arr[0] >= k) cout << sum;
    else cout << -1;

    return 0;
}