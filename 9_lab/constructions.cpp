#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> prefix_func(string s){
    int n = s.size();
    vector<int> vec(n);
    vec[0] = 0;
    for(int i = 1; i < n; i++){
        for(int l = 1; l <= i; l++){
            if(s.substr(0, l) == s.substr(i - l + 1, l))
                vec[i] = l;
        }
    }
    return vec;
}

int main(){
    string st, subst; cin >> st >> subst;
    int sum = 0;
    vector<int> ans = prefix_func(subst);

    if()



    for(int i = 0; i < subst.size(); i++){
        if(ans[i] != 0){
            sum++;
            cout << ans[i] << " ";
        }
    }
    // if(sum == 0){
    //     cout << -1;
    // } 
    cout << sum-1;
}