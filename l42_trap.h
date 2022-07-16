//
// Created by Ste7an on 2022/7/16.
//

#ifndef ALGORITHM_L42_TRAP_H
#define ALGORITHM_L42_TRAP_H
//接雨水

#include "vector"
#include "stack"
using namespace std;


int trap_dp(vector<int>& height){
    int n = height.size();

    //找到当前柱子左右两边 的最大值

    vector<int> left(n);
    left[0] = height[0];

    for(int i = 1; i < n; i++){
        left[i] = max(left[i - 1], height[i]);
    }
    vector<int> right(n);
    right[0] = height[n - 1];

    for(int i = n - 2; i >= 0; i--){
        right[i] = max(right[i + 1], height[i]);
    }

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans += min(left[i], right[i]) - height[i];
    }
    return ans;
}

int trap_stack(vector<int>& height){
    //维护一个单调递减的栈

    stack<int> stk;
    int n = height.size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        // 0,1,0,2,1,0,1,3,2,1,2,1
        // left > cur < i
        while(!stk.empty() && height[i] > height[stk.top()]){
            int cur = stk.top();
            stk.pop();
            if(stk.empty()) break;

            int left = stk.top();
            int curWidth = i - left - 1;
            int curHeight = min(height[i], height[left]) - height[cur];
            ans += curWidth * curHeight;
        }
        stk.push(i);
    }
    return ans;
}

#endif //ALGORITHM_L42_TRAP_H
