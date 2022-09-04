#include <bits/stdc++.h>
using namespace std;

int main(){
    const int N = 5;
    int s[][N] = {
        {3, 7, 9, 2, 7},
        {9, 8, 3, 5, 5},
        {1, 7, 9, 8, 5},
        {3, 8, 6, 4, 10},
        {6, 3, 9, 7, 8}
    };

    for (int k=1; k<N; k++){
        s[0][k] += s[0][k-1];
        s[k][0] += s[k-1][0];
    }

    for (int i=1; i<N; i++){
        for (int j=1; j<N; j++){
            s[i][j] = max(s[i-1][j], s[i][j-1]) + s[i][j];
        }
    }
    cout << s[N-1][N-1];
}