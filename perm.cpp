#include <bits/stdc++.h>
using namespace std;

void perm(vector<int>& v, int i, int n){
    if (i == n){
        for (auto x: v){
           cout << x << ", ";
        }
        cout << "\n";
        return;
    }
    for(int j=i; j<n; j++){
        swap(v[i], v[j]);
        perm(v, i+1, n);
        swap(v[j], v[i]);
    }
}

int main(){
    // int arr[] = {1,2,3,4};
    vector<int> v = {1,2,3, 4};
    // swap(arr[0], arr[1]);
    // for (auto x: arr){
    //     cout << x << " ";
    // }

    perm(v, 0, v.size());
}