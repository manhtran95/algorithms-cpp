#include <bits/stdc++.h>
using std::cout;
using std::string;
using std::to_string;

int f(int k){
    int a = 1;
    for (int i=2; i<=k; i++){
        a *= i;
    }
    return a;
}

string getPermutation(int n, int k) {
    int used[10] = {};
    int level = 1, digit = 1, size;
    string ans = "";
    while (k  > 1){
        size = f(n-level);
        while (k > size){
            k -= size;
            digit += 1;
            while (used[digit]) digit++;
        }
        ans += to_string(digit);
        used[digit] = 1;
        level++; digit = 1; 
        while (used[digit]) digit++;
    }
    for (int l=1; l<=n; l++){
        if (!used[l]){
            ans += to_string(l);
        }
    }
    return ans;
}

int main(){
    int n = 4;
    int k = 9;
    string ans = getPermutation(n, k);
    cout << ans << "\n";
}