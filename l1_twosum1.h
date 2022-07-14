//
// Created by Ste7an on 2022/7/14.
//

#ifndef ALGORITHM_TWOSUM1_H
#define ALGORITHM_TWOSUM1_H

//twoSum : 两数之和

#include "vector"
#include "unordered_map"
using namespace std;

vector<int> twoSum(std::vector<int>& nums, int target ){
    int n = nums.size();
    std::unordered_map<int, int> dict;

    for(int i = 0; i < n; ++i){

        if(dict.count(target - nums[i])){
            return {dict[target - nums[i]], i};
        }

        dict[nums[i]] = i;
    }

    return {};
}



#endif //ALGORITHM_TWOSUM1_H
