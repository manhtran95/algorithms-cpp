#include <bits/stdc++.h>
using std::string;
using std::cout;
using std::vector;
using std::stack;
using std::max;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int i = 0, n = heights.size(), ans = 0, h, li, w, right_val;
    while (i <= n){
        right_val = i < n? heights[i] : 0;
        while (s.size() > 0 && heights[s.top()] > right_val){
            // process s.top()
            h = heights[s.top()]; s.pop();
            li = !s.empty()? s.top() : -1;
            w = i - li - 1;
            // cout << "i " << i << ", li " << li << ", h " << h << ", w " << w << "\n";
            ans = max(ans, h*w);
        }
        s.push(i);
        i++;
    }
    return ans;
}

int main(){
    // vector<int> heights{2,1,5,6,2,3};
    vector<int> heights{2,4};
    int res = largestRectangleArea(heights);
    cout << res << "\n";
}