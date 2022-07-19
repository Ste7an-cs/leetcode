//
// Created by Ste7an on 2022/7/19.
//

#ifndef ALGORITHM_L128_LONGESTCONSECUTIVE_H
#define ALGORITHM_L128_LONGESTCONSECUTIVE_H
//最长 连续 序列

#include "vector"
#include "algorithm"
#include "unordered_set"
using namespace std;

int longestConsecutive(vector<int> nums){
    unordered_set<int> dict;
    for(const auto& x : nums){
        dict.insert(x);
    }

    int ans = 0;

    for(const auto& n : nums){
        if(!dict.count(n - 1)){
            int cnt = 1;
            int cur = n + 1;
            while(dict.count(cur)){
                cnt++;
                cur++;
            }
            ans = max(cnt, ans);
        }
    }
    return ans;
}
#endif //ALGORITHM_L128_LONGESTCONSECUTIVE_H
