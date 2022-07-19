//
// Created by Ste7an on 2022/7/19.
//

#ifndef ALGORITHM_L239_MAXSLIDINGWINDOW_H
#define ALGORITHM_L239_MAXSLIDINGWINDOW_H
//滑动 窗口 最大值

#include "vector"
#include "queue"
#include "deque"
using namespace std;

vector<int> maxSlidingWindow_queue(vector<int>& nums, int k){
    int n = nums.size();
    priority_queue<pair<int, int>> q;
    for(int i = 0; i < k; i++){
        q.emplace(nums[i], i);
    }
    vector<int> ans = {q.top().first};

    for(int i = k; i < n ; i++){
        q.emplace(nums[i],i);
        while(q.top().second <= i - k){//当前堆顶元素 不在窗口内
            q.pop();
        }

        ans.push_back(q.top().first);
    }
    return ans;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k){
    int n = nums.size();
    deque<int> q;

    //维护一个单调递减的 队列
    //首先队列中  放 k 个元素， 队首元素是最大的
    for(int i = 0; i < k; i++){
        while(!q.empty() && nums[i] >= nums[q.back()])
            q.pop_back();
        q.push_back(i);
    }

    vector<int> ans = {nums[q.front()]};

    for(int i = k; i < n; i++){//没进行一次 迭代 ， 窗口向右移动一个 位置
        while(!q.empty() && nums[i] >= nums[q.back()])
            q.pop_back();
        q.push_back(i);

        while(q.front() <= i - k ){//当 队首最大元素 不在当前窗口内 时 弹出
            q.pop_front();
        }

        //此时队首元素就是当前窗口内的 最大值
        //更新结果
        ans.push_back(nums[q.front()]);
    }
    return ans;
}

#endif //ALGORITHM_L239_MAXSLIDINGWINDOW_H
