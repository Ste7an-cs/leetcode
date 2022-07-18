//
// Created by Ste7an on 2022/7/18.
//

#ifndef ALGORITHM_L560_SUBARRAYSUM_H
#define ALGORITHM_L560_SUBARRAYSUM_H
//和为k的 子数组的 个数

#include "vector"
#include "unordered_map"
using namespace std;

int subarraySum(vector<int>& nums, int target){
    //[前缀和为k的数组， 次数]
   unordered_map<int,int> dict;

   int pre = 0, cnt = 0;
   dict[0] = 1;
   for(auto& x : nums){
       pre +=  x;
       //pre[i] - pre[j - 1] = target
       if(dict.count(pre - target)){
           cnt += dict[pre - target];
       }
       dict[pre]++;
   }
   return cnt;
}

#endif //ALGORITHM_L560_SUBARRAYSUM_H
