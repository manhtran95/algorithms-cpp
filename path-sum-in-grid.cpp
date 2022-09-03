#include <bits/stdc++.h>
using namespace std;

int main(){
    const int N = 5;
    int v[][N] = {
        {3, 7, 9, 2, 7},
        {9, 8, 3, 5, 5},
        {1, 7, 9, 8, 5},
        {3, 8, 6, 4, 10},
        {6, 3, 9, 7, 8}
    };
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    int s[N+1][N+1] = {};

    for (int i=0; i<N+1; i++){
        for (int j=0; j<N+1; j++){
            cout << s[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i=1; i<N+1; i++){
        for (int j=1; j<N+1; j++){
            s[i][j] = max(s[i-1][j], s[i][j-1]) + v[i-1][j-1];
        }
    }
    cout << s[N][N];
}