#include <bits/stdc++.h>
using namespace std;

int main(){
    set<int> a = {1,4,7,2,9};
    auto it1 = a.lower_bound(4);
    auto it2 = a.upper_bound(4);
    cout << *it1 << ", " << *it2;
}