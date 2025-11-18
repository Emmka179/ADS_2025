#include <iostream>
#include <algorithm>

class BSTShuffler {
private:
    int* arr;
    int* result;
    int size;
    
    struct Range {
        int start;
        int end;
        int resultIndex;
    };
    
public:
    BSTShuffler(int n) {
        size = (1 << n) - 1;
        arr = new int[size];
        result = new int[size];
    }
    
    ~BSTShuffler() {
        delete[] arr;
        delete[] result;
    }
    
    void readInput() {
        for (int i = 0; i < size; i++) {
            std::cin >> arr[i];
        }
    }
    
    void shuffle() {
        std::sort(arr, arr + size);
        
        Range* queue = new Range[size];
        int front = 0, rear = 0;
        
        queue[rear++] = {0, size - 1, 0};
        
        while (front < rear) {
            Range current = queue[front++];
            
            if (current.start > current.end) continue;
            
            int mid = (current.start + current.end) / 2;
            result[current.resultIndex] = arr[mid];
            
            if (mid - 1 >= current.start)
                queue[rear++] = {current.start, mid - 1, current.resultIndex * 2 + 1};
            if (mid + 1 <= current.end)
                queue[rear++] = {mid + 1, current.end, current.resultIndex * 2 + 2};
        }
        
        delete[] queue;
    }
    
    void printResult() {
        for (int i = 0; i < size; i++) {
            std::cout << result[i];
            if (i < size - 1) std::cout << " ";
        }
        std::cout << "\n";
    }
};

int main() {
    int N;
    std::cin >> N;
    
    BSTShuffler shuffler(N);
    shuffler.readInput();
    shuffler.shuffle();
    shuffler.printResult();
    
    return 0;
}