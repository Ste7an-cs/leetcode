//
// Created by Ste7an on 2022/7/15.
//

#ifndef ALGORITHM_L34_SEARCHRANGE_H
#define ALGORITHM_L34_SEARCHRANGE_H
//在排序数组中查找元素的第一次和最后一次出现的位置
//lower_bound  upper_bound
//不存在返回-1


//二分搜索

#include "vector"

using namespace std;


int lower_bound(vector<int>& nums, int target){

    int l = 0, r = nums.size() - 1, mid;
    int  ans = 0;
    while(l <= r){
        mid = l + ((r -  l) >> 1);
        if(nums[mid] >= target){
            r = mid - 1;
            ans = mid;
        }else{
            l = mid + 1;
        }
    }
    return ans;
}

int upper_bound(vector<int>& nums, int target){

    int l = 0, r = nums.size() - 1, mid;
    int  ans = nums.size();
    while(l <= r){
        mid = l + ((r -  l) >> 1);
        if(nums[mid] > target){ // 第一个大于target 的元素的位置
            r = mid - 1;
            ans = mid;
        }else{
            l = mid + 1;
        }
    }
    return ans;
}

vector<int> searchRange(vector<int>& nums, int target){
    if(nums.empty()) return {-1, -1};
    int lower = lower_bound(nums, target);
    int upper = upper_bound(nums, target) - 1;
    if(lower == nums.size() || nums[lower] != target){
        return {-1, -1};
    }

    return {lower, upper};

}



#endif //ALGORITHM_L34_SEARCHRANGE_H
