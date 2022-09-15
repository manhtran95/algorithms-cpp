#include <bits/stdc++.h>
using std::cout;
using std::vector;

int firstMissingPositive(vector<int>& nums) {
    int i = 0, n = nums.size(), aim = nums[0];
    while (i<n){
        if (aim > 0 && aim < n && i < n && nums[aim-1] != aim){
            std::swap(nums[i], nums[aim-1]);
        }else {
            i++;
        }
        aim = nums[i];
    }
    for (i = 1; i <= n; i++){
        if (nums[i-1] != i){
            return i;
        }
    }
    return i;
}

int main(){
    // [7,8,9,11,12]
    vector<int> v{2,1};
    int ans = firstMissingPositive(v);
    for (auto i:v)
        cout << i << " ";
    cout << "\n" << ans << "\n";
}