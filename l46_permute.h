//
// Created by Ste7an on 2022/7/18.
//

#ifndef ALGORITHM_L46_PERMUTE_H
#define ALGORITHM_L46_PERMUTE_H
#include "vector"

using namespace std;

void dfs(vector<int>& output, vector<vector<int>>& ans, int first, int len){
    if(first == len){
        ans.emplace_back(output);
    }

    for(int i = first; i < len; i++){
        swap(output[i], output[first]);
        dfs(output, ans, first + 1, len);
        swap(output[i], output[first]);
    }
}

vector<vector<int>> permute(vector<int> nums){
    vector<vector<int>> ans;
    int len = nums.size();
    dfs(nums, ans, 0, len);
    return ans;
}



#endif //ALGORITHM_L46_PERMUTE_H
