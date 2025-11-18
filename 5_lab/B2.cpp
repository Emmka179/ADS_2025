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

    void heapSort(){
        buildHeap();      //max -- arr[0]
        while(heapSize>0){
            swap(arr[0],arr[heapSize-1]);
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
    int n; cin >> n;
    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Heap h1(arr,n);   //arrsize>=heapsize
    h1.heapSize = n;

    h1.buildHeap();

    while(h1.heapSize > 1){
        int first = h1.arr[0];
        h1.deleteRoot();
        int second = h1.arr[0];
        h1.deleteRoot();

        if(first != second){
            h1.insertInHeap(first - second);
        }
    }
    if (h1.heapSize == 1)
        cout << h1.arr[0] << endl;
    else
        cout << 0 << endl;
}