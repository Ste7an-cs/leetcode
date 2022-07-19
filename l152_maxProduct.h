//
// Created by Ste7an on 2022/7/19.
//

#ifndef ALGORITHM_L152_MAXPRODUCT_H
#define ALGORITHM_L152_MAXPRODUCT_H
//乘积最大 子数组

#include "vector"
#include "algorithm"

using namespace std;

int maxProduct(vector<int>& nums){
    int n = nums.size();
    //因为数组中存在负数 所以需要同时算出 最大 和最小 子数组

    int maxF = nums[0], minF = nums[0], ans = nums[0];

    for(int i = 1; i < n; i++){
        int mx = maxF, mn = minF;
        maxF = max(nums[i], max(mn * nums[i], mx * nums[i]));
        minF = min(nums[i], min(mn * nums[i], mx * nums[i]));
        ans = max(maxF, ans);
    }
    return ans;
}
#endif //ALGORITHM_L152_MAXPRODUCT_H
