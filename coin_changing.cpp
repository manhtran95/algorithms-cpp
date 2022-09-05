#include <bits/stdc++.h>
using namespace std;

int solve(int);

int X = 9;
const int N = 9;
bool ready[N];
int value[N];
int coins[] = {1,3,5,7};

int main(){
    // if (2 < INFINITY) {
    //     cout << "yes\n";
    // }
    cout << solve(X);
}

int solve(int x) {
cout << "solve " << x << "\n";
if (x < 0) return N+1;
if (x == 0) return 0;
if (ready[x]) return value[x];
int best = N+1;
for (auto c : coins) {
    best = min(best, solve(x-c)+1);
}
cout << value[99] << "!!!\n";
value[x] = best;
ready[x] = true;
cout << "done solve " << x << ": " << best << "\n";
return best;
}