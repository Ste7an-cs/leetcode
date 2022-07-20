//
// Created by Ste7an on 2022/7/20.
//

#ifndef ALGORITHM_L300_LENGTHOFLIS_H
#define ALGORITHM_L300_LENGTHOFLIS_H
//最长递增子序列
//输入：nums = [10,9,2,5,3,7,101,18]
//输出：4
//解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。

#include "vector"

using namespace std;

int lengthOfLIS(vector<int>& nums){
    int n = nums.size();
    int len = 1;
    vector<int> dp(n+1);
    dp[len] = nums[0];

    for(int i = 1; i < n; i++){
        if(nums[i] > dp[len]){

            dp[++len] = nums[i];
        }else{//在dp数组中找到以一个比nums[i] 小的数
            int l =1, r = len;
            while(l <=r ){
                int mid = (l+r)/2;
                if(dp[mid] < nums[i]){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            dp[r + 1] = nums[i];
        }
    }
    return len;
}
#endif //ALGORITHM_L300_LENGTHOFLIS_H
