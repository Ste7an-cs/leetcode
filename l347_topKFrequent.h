//
// Created by Ste7an on 2022/7/18.
//

#ifndef ALGORITHM_L347_TOPKFREQUENT_H
#define ALGORITHM_L347_TOPKFREQUENT_H
//top k frequent
//输入: nums = [1,1,1,2,2,3], k = 2
//输出: [1,2]

#include "vector"
#include "queue"
#include "unordered_map"
#include "iostream"
using namespace std;

static bool cmp(pair<int,int>& m, pair<int,int> n){
    return m.second > n.second;
};
vector<int> topKFrequent(vector<int>& nums, int k){
    unordered_map<int,int> freq;
    for(auto& x : nums){
        ++freq[x];
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&cmp)> q(cmp);

    for(auto& [n, c] : freq){
        if(q.size() == k){
            if(q.top().second < c){
                q.pop();
                q.emplace(n, c);
            }
        }else q.emplace(n,c);
    }
    vector<int> ans;
    while(!q.empty()){
        ans.push_back(q.top().first);
        q.pop();
    }
    for(auto& x : ans){
        cout << x <<" ";
    }
    return ans;
}
#endif //ALGORITHM_L347_TOPKFREQUENT_H
