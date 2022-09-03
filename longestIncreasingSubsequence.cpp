#include <bits/stdc++.h>
using namespace std;

int main(){
    // int a = numeric_limits<int>::max();
    // cout << min(a, (int)pow(2,30));
    int arr[] = {6, 2, 5, 1, 7, 4, 8, 3};
    const int L = sizeof(arr) / sizeof(*arr);
    int lis[L] = {};
    lis[0] = 1;
    for (int i=1; i<L; i++){
        int prev_lis_max = 0;
        for (int j=0; j<i; j++){
            if (arr[j] < arr[i] && lis[j] > prev_lis_max){
                prev_lis_max = lis[j];
            } 
        }
        lis[i] = prev_lis_max + 1;
    }

    for (auto i: lis){
        cout << i << " ";
    }
    cout << "\n";

}