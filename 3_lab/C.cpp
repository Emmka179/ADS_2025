#include <iostream>
using namespace std;

int main(){
    int len, q;
    cin >> len >> q;

    int arr[len];
    int query[q][4];
    int ans[q] = {0};

    for (int i = 0; i < len; i++){
        cin >> arr[i];
    }

    for (int i = 0; i < q; i++){
        for (int j = 0; j < 4; j++){
            cin >> query[i][j];
        }
    }

    for (int i = 0; i<q; i++){
        for (int j = 0; j < len; j++){
            if (arr[j] >= query[i][0] && arr[j] <= query[i][1] || arr[j] >= query[i][2] && arr[j] <= query[i][3]){
                ans[i]++;
            }
        }
    }

    for(int i=0; i<q; i++){
        cout << ans[i] << endl;
    }
}