#include <iostream>
using namespace std;

class Dequeue
{
private:
    int *data;
    int head;
    int tail;
    bool full;
    int size;

public:
    int count;
    bool empty;
    Dequeue(int size)
    {
        data = new int[size];
        this->size = size;

        head = 0;
        tail = 0;
        count = 0;

        full = false;
        empty = true;
    }

    ~Dequeue()
    {
        delete[] data;
    }

    void back_enqueue(int value)
    {
        empty = false;

        if (!full)
        {
            data[tail] = value;
            count++;
            if (tail == size - 1)
            {
                tail = 0;
            }
            else
            {
                tail++;
            }
            if (tail == head)
            {
                full = true;
            }
        }
    }

    void front_enqueue(int value)
    {
        empty = false;
        if (!full)
        {
            if (head == 0)
            {
                head = size - 1;
            }
            else
            {
                head--;
            }
            data[head] = value;
            count++;
            if (head == tail)
            {
                full = true;
            }
        }
    }

    int front_dequeue()
    {
        full = false;

        int x = -2147483647;

        if (!empty)
        {
            x = data[head];
            count--;
            if (head == size - 1)
            {
                head = 0;
            }
            else
            {
                head++;
            }
            if (tail == head)
            {
                empty = true;
            }
        }
        else
        {
            return 0;
        }
        return x;
    }

    int back_dequeue()
    {
        full = false;

        int x = -2147483647;

        if (!empty)
        {
            count--;
            if (tail == 0)
            {
                tail = size - 1;
            }
            else
            {
                tail--;
            }
            x = data[tail];

            if (tail == head)
            {
                empty = true;
            }
        }
        else
        {
            return 0;
        }
        return x;
    }

    void print()
    {
        int i = head;
        while (i != tail)
        {
            cout << data[i] << ' ';
            if (i == size - 1)
            {
                i = 0;
            }
            else
            {
                i++;
            }
        }
        cout << '\n';
    }
};

int main(){
    int t; cin >> t;

    while (t--){
        int n; cin >> n;

        Dequeue dq(100000);

        for (int j = 0; j < n; j++){
            int c = n - j;

            dq.front_enqueue(n - j);

            while (c > 0){
                dq.front_enqueue(dq.back_dequeue());
                c--;
            }
        }

        dq.print();
    }
    return 0;
}
