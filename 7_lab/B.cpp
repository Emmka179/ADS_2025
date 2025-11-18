#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    int m;
    int arr2[n];

    for(int i = 0; i < n; i++) cin >> arr[i];

    cin >> m;

    for(int i = 0; i < m; i++) cin >> arr2[i];

    int ans[n + m];

    // сравниваем числа из первого и второго массива какое из них больше
    // потом закидываем их в массив ans
    // выводим в конце массив ans

    int i, j, k; i = j = k = 0;

    while(k < n + m){
        if(i < n && (j >= m || arr[i] < arr2[j])){
            ans[k] = arr[i];
            i++;
            k++;
        } 
        else{
            ans[k] = arr2[j];
            j++;
            k++;
        }
    }

    for(int i = 0; i < n+m; i++) cout << ans[i] << " ";

}