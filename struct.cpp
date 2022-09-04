#include <bits/stdc++.h>
using namespace std;
int main(){
    struct P {
        int x, y;
        bool operator<(const P &p) {
            if (x != p.x) return x < p.x;
            else return y < p.y;
        }
    };

    P p1 = P {1, 3};
    P p2 = P {1, 2};
    if (p1 < p2) cout << "p1 < p2\n"; 
    else cout << "p1 >= p2\n";
}