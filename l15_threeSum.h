//
// Created by Ste7an on 2022/7/16.
//

#ifndef ALGORITHM_L15_THREESUM_H
#define ALGORITHM_L15_THREESUM_H


//输入：nums = [-1,0,1,2,-1,-4]
//输出：[[-1,-1,2],[-1,0,1]]

#include "vector"
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    //固定一个数字
    //枚举另外两个数字

    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int first = 0; first < n; first++){
        if(first > 0 && nums[first -  1] == nums[first]){ // 枚举 a 并去重
            continue;
        }

        int third = n - 1;
        int target = -nums[first];
        for(int second = first + 1; second < n; ++second){ // 枚举 b 并去重
            if(second > first + 1 && nums[second - 1] == nums[second]){
                continue;
            }

            //枚举 c ， c初始为 最大值
            while(second < third && nums[second] + nums[third] > target){
                --third;
            }

            if(second == third){
                break;
            }
            if(nums[second] + nums[third] == target){
                ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
    }
    return ans;
}

#endif //ALGORITHM_L15_THREESUM_H
