#include <iostream>
using namespace std;

void insSort(int* arr, int size){
    int i;
    for(int j=1; j < size; j++){
        int key = arr[j];
        i = j-1;
        while(i >= 0 && arr[i] > key){
            //shift:
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key; //insertion
    }
}

int main(){
    int arr[7] = {4, 5, 8, 4, 2, 11, -1};

    insSort(arr, 7);
    for(int i = 0; i < 7; i++){
        cout << arr[i] << " ";
    }
    return 0;
}