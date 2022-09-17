#include <bits/stdc++.h>
// using namespace std;

void search(int);
const int n = 4;
int column[n] = {};
int diag1[2*n] = {};
int diag2[2*n] = {};
int count = 0;

int main(){
    search(0);
    std::cout << count << "\n";
}

void search(int y) {
    if (y == n) {
        count++;
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x+y] || diag2[x-y+n]) continue;
        column[x] = diag1[x+y] = diag2[x-y+n] = 1;
        search(y+1);
        column[x] = diag1[x+y] = diag2[x-y+n] = 0;
    }
}