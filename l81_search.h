//
// Created by Ste7an on 2022/7/18.
//

#ifndef ALGORITHM_L81_SEARCH_H
#define ALGORITHM_L81_SEARCH_H
//搜索旋转数组
//Input: nums = [2,5,6,0,0,1,2], target = 0
//Output: true


#include "vector"

using namespace std;

bool search(vector<int> nums, int target){
    int start = 0, end = nums.size() - 1;

    while(start <= end){
        int mid = (end + start) / 2;
        if(nums[mid] == target){
            return true;
        }
        if(nums[start] == nums[mid]){
            start++;
        }else if(nums[mid] <= nums[end]){// 右半部分 有序
            if(target > nums[mid] && nums[mid] <= nums[end]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }else{ // 左区间 是递增的
            if(target >= nums[start] && target < nums[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
    }
    return false;
}
#endif //ALGORITHM_L81_SEARCH_H
