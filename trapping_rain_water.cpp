#include <bits/stdc++.h>
using std::string;
using std::vector;
using std::cout;
using std::max;
using std::min;



int trap(vector<int>& height) {
        vector<int> leftTrap{0};
        vector<int> rightTrap{0};
        int N = height.size();
        int leftMax = height[0], rightMax = height[N-1];
        for (int i=1; i<N-1; i++){
            leftMax = max(leftMax, height[i]);
            leftTrap.push_back(leftMax - height[i]);
        }
        for (int i=N-2; i>0; i--){
            rightMax = max(rightMax, height[i]);
            rightTrap.push_back(rightMax - height[i]);
        }
        int trap;
        int ans = 0;
        for (int i=1; i<N-1; i++){
            trap = min(leftTrap[i], rightTrap[N-1-i]);
            ans += trap;
        }
        return ans;
}

int main(){
    vector<int> v{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(v) << "\n";
}