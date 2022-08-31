
#include <bits/stdc++.h>
using namespace std;
int main() {
// solution comes here
    int input [] = {-1, 2, 4, -3, 5, 2, -5, 2};
    const int L = sizeof(input) / sizeof(*input);
    cout << typeid(input).name() << "\n";
    cout << typeid(*input).name() << "\n";
    cout << (*input) << "\n";
    cout << L << "\n";
    int arr [L][L] = {};
    int maxRes = 0;
    for (int i = 0; i < L; ++i){
        // cout << "1";
        arr[i][i] = input[i];
    }
    for (int i=0; i < L; ++i) {
        for (int j=i+1; j<L; ++j){
            // cout << "2";
            arr[i][j] = arr[i][j-1] + input[j];
            maxRes = max(maxRes, arr[i][j]);
        }
    }
    for (int i=0; i < L; ++i) {
        for (int j=0; j<L; ++j){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << maxRes << "\n";
}