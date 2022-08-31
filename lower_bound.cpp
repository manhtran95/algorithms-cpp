#include <bits/stdc++.h>
using namespace std;

int main(){
    int array[] = {1,2,3,3,4,5};
    const int n = sizeof(array) / sizeof(*array);
    int x = 3;
    auto a = lower_bound(array, array+n, x);
    auto b = upper_bound(array, array+n, x);
    cout << b << "\n";
}